/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
/**
 * @file
 *
 * Scope guard implementation by S.T.L.
 *
 * @requiredheaders exception, memory
 */

#pragma once
#ifndef PLATFORM_SCOPEWARDEN_H
#define PLATFORM_SCOPEWARDEN_H

#include <exception>
#include <memory>

#include <CoreUtils/Assert.h>

/**
 * Scope guard implementation.
 *
 * The scope guard is given a cleanup functor on creation which it will run when
 * it is destroyed. Calling Clear will stop the guard from calling the cleanup
 * functor on destruction.
 */
template <typename F>
class
ScopeWarden
{
public:
    /**
     * Creates a new scope guard.
     */
    explicit
    ScopeWarden(
        F& f    /**< The cleanup functor.
                 *   The functor lifetime must be at least as long as the guard.
                 */
    ) noexcept
    :
        m_p(std::addressof(f))
    {
        // do nothing
    }

    /**
     * Clear the scope guard, the cleanup functor will not be called anymore.
     */
    void
    Clear() noexcept
    {
        m_p = nullptr;
    }

    /**
     * Runs the cleanup functor unless Clear has been called.
     */
    ~ScopeWarden() noexcept
    {
        if (m_p)
        {
#ifndef _XBOX // don't do exception stuff on xbox
            try
            {
#endif
                (*m_p)();
#ifndef _XBOX // don't do exception stuff on xbox
            }
            catch (...)
            {
                SpectreAssertExpr(false, L"The cleanup lambda should not throw.");
                std::terminate();
            }
#endif
        }
    }

private:
    F * m_p;

    explicit ScopeWarden(F&&);
    ScopeWarden(const ScopeWarden&);
    ScopeWarden& operator=(const ScopeWarden&);
};

/**
 * Scope guard macro.
 *
 * Internally creates a ScopeWarden object with the given name and creates a
 * cleanup functor from the statements given in the arguments.
 */
#define SCOPE_WARDEN(NAME, ...)                \
    auto xx##NAME##xx = [&]() { __VA_ARGS__ }; \
    ScopeWarden<decltype(xx##NAME##xx)> NAME(xx##NAME##xx)

#endif
