/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include "Cancellation.h"
#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

namespace Spectre
{
    namespace Utils
    {
        class ThreadPool
        {
        public:
            enum class TaskStatus : int
            {
                Scheduled = 0,
                Started,
                Finished,
                Cancelled,
                Exception
            };

            SPECTRE_SMART_POINTER(TaskHandler);

            class TaskHandler
            {
            public:
                typedef std::function<void(TaskHandler*, TaskStatus)> StatusChangedCallback;

                TaskHandler() :
                    m_status(TaskStatus::Scheduled)
                {
                    static std::atomic<uint32_t> s_id = { 0 };
                    m_id = ++s_id;

                    m_cancellationToken = Utils::MakeCancellationToken();
                }

                static TaskHandlerPtr GetCompletedTaskHandler()
                {
                    auto th = std::make_shared<ThreadPool::TaskHandler>();
                    th->m_status = TaskStatus::Finished;
                    return th;
                }

                void SetStatusChangedCallback(StatusChangedCallback callback)
                {
                    {
                        std::lock_guard<std::mutex> lock(m_mutex);
                        m_callback = callback;
                        if (m_status == TaskStatus::Scheduled)
                        {
                            return;
                        }
                    }
                    //  If status is different from default -> notify
                    ChangeStatus(m_status);
                }

                TaskStatus GetStatus()
                {
                    return m_status.load();
                }

                void Cancel()
                {
                    m_cancellationToken->Cancel();
                }

                uint32_t GetId() const
                {
                    return m_id;
                }

                ICancellationTokenPtr GetCancellationToken() const
                {
                    return m_cancellationToken;
                }

                void ChangeStatus(TaskStatus newStatus)
                {
                    std::lock_guard<std::mutex> lock(m_mutex);
                    if (m_callback)
                    {
                        m_callback(this, newStatus);
                    }
                    m_status = newStatus;
                }

                void Wait(bool waitOnCancelled = false)
                {
                    while ((m_status == TaskStatus::Started || m_status == TaskStatus::Scheduled)
                        && (waitOnCancelled || !m_cancellationToken->IsCancelled()))
                    {
                        std::this_thread::yield();
                    }
                }

            private:
                ICancellationTokenPtr m_cancellationToken;
                std::atomic<TaskStatus> m_status;
                uint32_t                m_id;
                StatusChangedCallback   m_callback;
                std::mutex              m_mutex;
            };

            typedef std::pair < TaskHandlerPtr, std::function<void(Utils::ICancellationTokenPtr) > > TaskPair;

            ThreadPool(size_t);
            ~ThreadPool();

            template<class F>
            TaskHandlerPtr Enqueue(F f)
            {
                std::unique_lock<std::mutex> lock(m_queueMutex);
                auto taskHandler = std::make_shared<TaskHandler>();
                m_tasks.push_back(std::make_pair(taskHandler, std::function<void(Utils::ICancellationTokenPtr)>(f)));
                m_cv.notify_all();
                return taskHandler;
            }

        private:
            friend class Worker;

            // need to keep track of threads so we can join them
            std::vector<std::thread> m_workers;

            std::deque < TaskPair >  m_tasks;

            // synchronization
            std::mutex              m_notifyLock;
            std::mutex              m_queueMutex;
            std::condition_variable m_cv;
            bool                    m_stop;
        };

        // our worker thread objects
        class Worker
        {
        public:
            Worker(ThreadPool &s);
            void operator()();
        private:
            ThreadPool& m_pool;
        };

        ThreadPool::TaskHandlerPtr GetCompletedTaskHandler();

        // Deprecated: older name for backward compatibility
        SPECTRE_DEPRECATED("Please use Spectre::Utils::GetCompletedTaskHandler")
        ThreadPool::TaskHandlerPtr GetCompletedTaskHanlder();

    } // Utils

} // Spectre
