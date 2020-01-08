//
// Copyright (C) Microsoft.  All rights reserved.
//

#pragma once

#include <memory>

namespace Spectre
{
    namespace Utils
    {
        class SharedMutex
        {
        public:
            SharedMutex();
            ~SharedMutex();

            SharedMutex(const SharedMutex& other) = delete;
            const SharedMutex& operator=(const SharedMutex& other) const = delete;

            void lock();
            bool try_lock();
            void unlock();

            void lock_shared();
            bool try_lock_shared();
            void unlock_shared();

        private:
            class impl;
            std::unique_ptr<impl> m_pImpl;
        };
    }
}
