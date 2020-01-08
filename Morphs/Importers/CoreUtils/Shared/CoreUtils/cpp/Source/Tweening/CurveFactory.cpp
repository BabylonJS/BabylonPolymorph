/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "../CoreUtilsPch.h"

#include <CoreUtils/Tweening/Curves.h>
#include <CoreUtils/Tweening/CurveFactory.h>
#include <CoreUtils/SmartThrow.h>

//--------------------------------------------------------------------------------

using namespace Spectre::Utils::Tweening;

std::unique_ptr<ICurve> Spectre::Utils::Tweening::CurveFactory::GetCurve(CurveType type)
{
    switch (type)
    {
        case CurveType::Linear: return std::make_unique<LinearCurve>();
        case CurveType::QuadraticEaseIn: return std::make_unique<QuadraticEaseInCurve>();
        case CurveType::QuadraticEaseOut: return std::make_unique<QuadraticEaseOutCurve>();
        case CurveType::QuadraticEaseInOut: return std::make_unique<QuadraticEaseInOutCurve>();
        case CurveType::ExponentiaEaseIn: return std::make_unique<ExponentialEaseInCurve>();
        case CurveType::ExponentiaEaseOut: return std::make_unique<ExponentialEaseOutCurve>();
        case CurveType::ExponentiaEaseInOut: return std::make_unique<ExponentialEaseInOutCurve>();
        case CurveType::SineEaseIn: return std::make_unique<SineEaseInCurve>();
        case CurveType::SineEaseOut: return std::make_unique<SineEaseOutCurve>();
        case CurveType::SineEaseInOut: return std::make_unique<SineEaseInOutCurve>();
        case CurveType::BackEaseIn: return std::make_unique<BackEaseInCurve>();
        case CurveType::BackEaseOut: return std::make_unique<BackEaseOutCurve>();
        case CurveType::BackEaseInOut: return std::make_unique<BackEaseInOutCurve>();
        case CurveType::BounceEaseIn: return std::make_unique<BounceEaseInCurve>();
        case CurveType::BounceEaseOut: return std::make_unique<BounceEaseOutCurve>();
        case CurveType::BounceEaseInOut: return std::make_unique<BounceEaseInOutCurve>();
        case CurveType::ElasticEaseIn: return std::make_unique<ElasticEaseInCurve>();
        case CurveType::ElasticEaseOut: return std::make_unique<ElasticEaseOutCurve>();
        case CurveType::ElasticEaseInOut: return std::make_unique<ElasticEaseInOutCurve>();
        default:
            throw SpectreException("Curve type is not supported");
    }
}

//--------------------------------------------------------------------------------
