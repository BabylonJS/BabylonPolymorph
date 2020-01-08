/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#if !defined(_ATOMIC_)
#include <atomic>
#endif // _ATOMIC_

#if !defined(COREUTILS_TRACE_H_INCLUDED)
#include <CoreUtils/Trace.h>
#endif // COREUTILS_TRACE_H_INCLUDED

DECLARE_TRACE_AREA(Tracked);

namespace Spectre {

namespace Utils {

    template<class TClass>
    class InstanceCounter
    {
    protected:
        InstanceCounter()
        {
#if FEATURE_TRACEENABLED
            //auto num = ++sCounter;
            //TRACE_INFO(Tracked, "%s C-tor, number of instances = %d", typeid(TClass).name(), num);
#endif
        }

        ~InstanceCounter()
        {
#if FEATURE_TRACEENABLED
            //auto num = --sCounter;
            //TRACE_INFO(Tracked, "%s D-tor, number of instances = %d", typeid(TClass).name(), num);
#endif
        }

    private:
        InstanceCounter(InstanceCounter const&);
        InstanceCounter& operator=(InstanceCounter const&);

        static std::atomic<size_t> sCounter;
    };

template<class TClass> std::atomic<size_t> InstanceCounter<TClass>::sCounter;



template<class T, bool enabled = true, size_t MIN_TO_TRACK_T = 0, size_t MAX_ALLOWED = 1024>
class Tracked
{
public:
    Tracked()
    {
#if FEATURE_TRACEENABLED
        if (enabled)
        {
            auto num = ++s_num;
            if (num >= MIN_TO_TRACK_T)
            {
                TRACE_INFO(Tracked, "Creating a %s at %p, %Iu alive", typeid(T).name(), (void*)this, num);
            }
            if (num > MAX_ALLOWED)
            {
                TRACE_ERROR(Tracked, "We've got too many %s, max alloced is %Iu", typeid(T).name(), MAX_ALLOWED);
            }
        }
#endif
    }
    ~Tracked()
    {
#if FEATURE_TRACEENABLED
        if (enabled)
        {
            auto num = --s_num;
            if (num >= MIN_TO_TRACK_T)
            {
                TRACE_INFO(Tracked, "Destroying a %s at %p, %Iu alive", typeid(T).name(), (void*)this, num);
            }
        }
#endif
    }
private:
#if FEATURE_TRACEENABLED
    static std::atomic<size_t> s_num;
#endif
    Tracked(Tracked const&);
    Tracked& operator=(Tracked const&);
};
#if FEATURE_TRACEENABLED
template<class T, bool enabled, size_t MIN_TO_TRACK_T, size_t MAX_ALLOWED> std::atomic<size_t> Tracked<T, enabled, MIN_TO_TRACK_T, MAX_ALLOWED>::s_num;
#endif


#ifdef __cplusplus_winrt

template<class T, size_t MIN_TO_TRACK_T = 0, size_t MAX_ALLOWED = 1024>
private ref class TrackedRT
{
private:
    Tracked<T, true, MIN_TO_TRACK_T, MAX_ALLOWED> m_tracked;
};

#endif // __cplusplus_winrt

} // Utils

} // Spectre
