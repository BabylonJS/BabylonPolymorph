//
// Copyright (C) Microsoft.  All rights reserved.
//

#include "../CoreUtilsPch.h"
#include <CoreUtils/SharedMutex.h>
#include <CoreUtils/SmartThrow.h>

#include <pthread.h>

namespace Spectre
{
    namespace Utils
    {

        //-----------------------------------------------------------------------------

        // This is a pthread-based implementation of a SharedMutex, as in
        // std::shared_timed_mutex but without the timed portions which are
        // not used by the Canvas3D codebase.  macOS 10.11 El Capitan does not
        // have std::shared_timed_mutex in the C++ std libs.

        class SharedMutex::impl
        {
        public:
            pthread_rwlock_t m_lock;
        };

        //-----------------------------------------------------------------------------

        SharedMutex::SharedMutex()
            : m_pImpl(std::make_unique<impl>())
        {
            int ret = pthread_rwlock_init(&m_pImpl->m_lock, nullptr);
            switch (ret)
            {
                case ENOMEM:
                    throw Utils::SpectreException("pthread::impl out of memory");
                case EAGAIN:
                    throw Utils::SpectreException("pthread::impl resource unavailable, try again");
                case EPERM:
                    throw Utils::SpectreException("pthread::impl operation not permitted");
                default:
                    break;
            }
        }

        SharedMutex::~SharedMutex()
        {
            // The destructors are noexcept so swallow all the errors
            pthread_rwlock_destroy(&m_pImpl->m_lock);
        }

        void SharedMutex::lock()
        {
            int ret = pthread_rwlock_wrlock(&m_pImpl->m_lock);
            switch (ret)
            {
                case EDEADLK:
                    throw Utils::SpectreException("pthread::lock deadlock situation detected");
                case EINVAL:
                    throw Utils::SpectreException("pthread::lock given invalid rwlock");
                default:
                    break;
            }
        }

        bool SharedMutex::try_lock()
        {
            int ret = pthread_rwlock_trywrlock(&m_pImpl->m_lock);
            switch (ret)
            {
                case EBUSY:
                    return false;
                case EINVAL:
                    throw Utils::SpectreException("pthread::try_lock given invalid rwlock");
                default:
                    break;
            }
            return true;
        }

        void SharedMutex::unlock()
        {
            int ret = pthread_rwlock_unlock(&m_pImpl->m_lock);
            if (ret == EINVAL)
            {
                throw Utils::SpectreException("pthread::unlock given invalid rwlock");
            }
            // Ignoring EPERM for parity with std::mutex which has undefined behaviour
            // if you unlock something you don't have locked.
        }

        void SharedMutex::lock_shared()
        {
            int ret;
            do
            {
                ret = pthread_rwlock_rdlock(&m_pImpl->m_lock);
            } while (ret == EAGAIN);
            switch (ret)
            {
                case EDEADLK:
                    throw Utils::SpectreException("pthread::lock_shared deadlock situation detected");
                case EINVAL:
                    throw Utils::SpectreException("pthread::lock_shared given invalid rwlock");
                default:
                    break;
            }
        }

        bool SharedMutex::try_lock_shared()
        {
            int ret = pthread_rwlock_tryrdlock(&m_pImpl->m_lock);
            switch (ret)
            {
                case EBUSY:
                case EAGAIN:
                    return false;
                case EINVAL:
                    throw Utils::SpectreException("pthread::try_lock_shared given invalid rwlock");
                default:
                    break;
            }
            return true;
        }

        void SharedMutex::unlock_shared()
        {
            unlock();
        }

    }
}
