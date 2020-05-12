/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/ThreadPool.h>
#include <CoreUtils/Trace.h>

DEFINE_TRACE_AREA(ThreadPool, 0);

Babylon::Utils::Worker::Worker(ThreadPool &s) :
    m_pool(s)
{
}

void Babylon::Utils::Worker::operator()()
{
    while (true)
    {
        ThreadPool::TaskPair task_pair;
        {
            std::unique_lock<std::mutex> lock(m_pool.m_queueMutex);

            if (m_pool.m_tasks.empty() && !m_pool.m_stop)
            {
                m_pool.m_cv.wait(lock, [this] {
                    return !m_pool.m_tasks.empty() || m_pool.m_stop;
                });
            }

            if (m_pool.m_stop)
            {
                return;
            }

            task_pair = m_pool.m_tasks.front();
            m_pool.m_tasks.pop_front();
        }

        try
        {
            task_pair.first->ChangeStatus(ThreadPool::TaskStatus::Started);
            task_pair.second(task_pair.first->GetCancellationToken());
            task_pair.first->ChangeStatus(ThreadPool::TaskStatus::Finished);
        }
        catch (Babylon::Utils::CancelledException const&)
        {
            task_pair.first->ChangeStatus(ThreadPool::TaskStatus::Cancelled);
        }
        catch (...)
        {
            TRACE_IMPORTANT(ThreadPool, "Thread pool task threw exception. Task has been abadnoned.");
            task_pair.first->ChangeStatus(ThreadPool::TaskStatus::Exception);
        }
    }
}

Babylon::Utils::ThreadPool::ThreadPool(size_t count) :
    m_stop(false)
{
    for (size_t i = 0; i < count; i++)
    {
        m_workers.push_back(std::thread(Worker(*this)));
    }
}

Babylon::Utils::ThreadPool::~ThreadPool()
{
    std::unique_lock<std::mutex> lock(m_queueMutex);
    m_stop = true;
    m_cv.notify_all();
    lock.unlock();

    for (auto& t : m_workers)
    {
        t.join();
    }
    m_workers.clear();
}

Babylon::Utils::ThreadPool::TaskHandlerPtr Babylon::Utils::GetCompletedTaskHandler()
{
    return ThreadPool::TaskHandler::GetCompletedTaskHandler();
}

Babylon::Utils::ThreadPool::TaskHandlerPtr Babylon::Utils::GetCompletedTaskHanlder()
{
    return GetCompletedTaskHandler();
}
