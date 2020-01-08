/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "../CoreUtilsPch.h"

#include <CoreUtils/Tweening/Curves.h>
#include <CoreUtils/Math/SpectreMath.h>

#include <cmath>

namespace
{
    // Define easing functions in terms of the ease-in function.
    template<typename EaseInFunc>
    double EaseIn(double t, EaseInFunc easeInFunc)
    {
        t = std::min(std::max(t, 0.0), 1.0);
        return easeInFunc(t);
    }

    template<typename EaseInFunc>
    double EaseOut(double t, EaseInFunc easeInFunc)
    {
        t = std::min(std::max(t, 0.0), 1.0);
        return 1.0 - easeInFunc(1.0 - t);
    }

    template<typename EaseInFunc>
    double EaseInOut(double t, EaseInFunc easeInFunc)
    {
        t = std::min(std::max(t, 0.0), 1.0);
        if (t < 0.5)
        {
            return easeInFunc(t * 2.0) / 2.0;
        }
        else
        {
            return 1.0 - easeInFunc((1.0 - t) * 2.0) / 2.0;
        }
    }

    inline double Quadratic(double t)
    {
        return t * t;
    }

    inline double Cubic(double t)
    {
        return t * t * t;
    }

    inline double Quartic(double t)
    {
        return t * t * t * t;
    }

    double BounceEaseOut(double progress)
    {
        const double firstBounce = 1 / 2.75;
        const double secondBounce = 2 / 2.75;
        const double thirdBounce = 2.5 / 2.75;
        const double bounceModifier = 7.5625;

        if (progress < firstBounce)
        {
            return bounceModifier * progress * progress;
        }
        else if (progress < secondBounce)
        {
            progress -= (1.5 / 2.75);
            return bounceModifier * progress * progress + (3.0 / 4.0);
        }
        else if (progress < thirdBounce)
        {
            progress -= (2.25 / 2.75);
            return bounceModifier * progress * progress + (15.0 / 16.0);
        }
        else
        {
            progress -= (2.625 / 2.75);
            return bounceModifier * progress * progress + (63.0 / 64.0);
        }
    }

    double BounceEaseIn(double progress)
    {
        return 1.0 - BounceEaseOut(1.0 - progress);
    }
}


using namespace Spectre::Utils::Math;
//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::LinearCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return progress;
}

//--------------------------------------------------------------------------------

//quadratic
double Spectre::Utils::Tweening::QuadraticEaseInCurve::Remap(double progress) const
{
    return EaseIn(progress, Quadratic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::QuadraticEaseOutCurve::Remap(double progress) const
{
    return EaseOut(progress, Quadratic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::QuadraticEaseInOutCurve::Remap(double progress) const
{
    return EaseInOut(progress, Quadratic);
}

//--------------------------------------------------------------------------------

//cubic
double Spectre::Utils::Tweening::CubicEaseInCurve::Remap(double progress) const
{
    return EaseIn(progress, Cubic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::CubicEaseOutCurve::Remap(double progress) const
{
    return EaseOut(progress, Cubic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::CubicEaseInOutCurve::Remap(double progress) const
{
    return EaseInOut(progress, Cubic);
}

//--------------------------------------------------------------------------------

//quartic
double Spectre::Utils::Tweening::QuarticEaseInCurve::Remap(double progress) const
{
    return EaseIn(progress, Quartic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::QuarticEaseOutCurve::Remap(double progress) const
{
    return EaseOut(progress, Quartic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::QuarticEaseInOutCurve::Remap(double progress) const
{
    return EaseInOut(progress, Quartic);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ExponentialEaseInCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    double k = pow(2, -10); // 1/1024
    double c = (1 - k); // 1023/1024
    return (pow(2, 10 * (progress - 1)) - k) / c;
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ExponentialEaseOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    double k = pow(2, -10); // 1/1024
    double c = (1 - k); // 1023/1024
    return (1-pow(2, -10 * progress))/c;
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ExponentialEaseInOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    progress /= (1.0 / 2.0);
    if (progress < 1.0)
    {
        return (1.0 / 2.0) * pow(2, 10 * (progress - 1.0));
    }
    else
    {
        return (1.0 / 2.0) * (-pow(2, -10 * (progress - 1.0)) + 2.0);
    }
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::SineEaseInCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return -1.0 * cos(progress * (Math::kPi * 0.5)) + 1.0;
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::SineEaseOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return sin(progress * (Math::kPi * 0.5));
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::SineEaseInOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return -(1.0 / 2.0) * (cos(Math::kPi * progress) - 1.0);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BackEaseInCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    const double s = 1.70158;
    return progress * progress * ((s + 1) * progress - s);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BackEaseOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    progress -= 1;
    const double s = 1.70158;
    return progress * progress * ((s + 1) * progress + s) + 1;
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BackEaseInOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    const double s = 1.70158 * (61.0 / 40.0);
    progress /= (1.0 / 2.0);
    if (progress < 1.0)
    {
        return (1.0 / 2.0) * (progress * progress *((s + 1.0) * progress - s));
    }
    else
    {
        progress -= 2;
        return (1.0 / 2.0) * (progress * progress * ((s + 1.0) * progress + s) + 2.0);
    }
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BounceEaseInCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return BounceEaseIn(progress);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BounceEaseOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    return BounceEaseOut(progress);
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::BounceEaseInOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    if (progress < 0.5)
    {
        return (1.0 / 2.0) * BounceEaseIn(progress * 2.0);
    }
    else
    {
        return (BounceEaseOut((progress * 2.0) - 1.0) * (1.0 / 2.0)) + (1.0 / 2.0);
    }
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ElasticEaseInCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    const double p = 0.3;
    const double s = p / 4.0;
    progress -= 1.0;
    const double postFix = pow(2, 10 * progress);
    return -(postFix * sin((progress - s) * (2 * Math::kPi) / p));
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ElasticEaseOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    const double p = 0.3;
    const double s = p / 4;
    const double postFix = pow(2, -10 * progress);
    const double k = (progress - s) * (2 * Math::kPi) / p;
    const double sinConstant = sin(k);
    return (postFix * sinConstant) + 1;
}

//--------------------------------------------------------------------------------

double Spectre::Utils::Tweening::ElasticEaseInOutCurve::Remap(double progress) const
{
    //  Special case returning exactly "to" value if progress equals / greater than 1.0
    if (progress >= 1.0)
        return 1.0;
    //  Special case returning exactly "from" value if progress equals / less than 0.0
    if (progress <= 0.0)
        return 0.0;

    progress /= (1.0 / 2.0);
    const double p = 0.3 * 1.5;
    const double s = p / 4;

    const double t = progress - 1.0;
    const double k = (t - s) * (2 * Math::kPi) / p;

    if (progress < 1.0)
    {
        double postFix = pow(2, 10 * t);
        return -(1.0 / 2.0) * (postFix * sin(k));
    }
    else
    {
        double postFix = pow(2, -10 * t);
        return (postFix * sin(k) * (1.0 / 2.0)) + 1.0;
    }
}

//--------------------------------------------------------------------------------

