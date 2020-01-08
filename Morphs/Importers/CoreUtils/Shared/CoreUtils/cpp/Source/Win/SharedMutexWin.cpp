//
// Copyright (C) 2017 Microsoft.
//

#include "../CoreUtilsPch.h"
#include <CoreUtils/SharedMutex.h>

#include <shared_mutex>

namespace Spectre
{
    namespace Utils
    {

        //-------------------------------------------------------------------------------------------------------------------------

        class SharedMutex::impl
        {
        public:
            std::shared_timed_mutex m_mutex;
        };

        //-------------------------------------------------------------------------------------------------------------------------

        SharedMutex::SharedMutex()
            : m_pImpl(std::make_unique<impl>())
        {
        }

        SharedMutex::~SharedMutex() = default;

        void SharedMutex::lock()
        {
            m_pImpl->m_mutex.lock();
        }

        bool SharedMutex::try_lock()
        {
            return m_pImpl->m_mutex.try_lock();
        }

        void SharedMutex::unlock()
        {
            m_pImpl->m_mutex.unlock();
        }

        void SharedMutex::lock_shared()
        {
            m_pImpl->m_mutex.lock_shared();
        }

        bool SharedMutex::try_lock_shared()
        {
            return m_pImpl->m_mutex.try_lock_shared();
        }

        void SharedMutex::unlock_shared()
        {
            m_pImpl->m_mutex.unlock_shared();
        }

    }
}
