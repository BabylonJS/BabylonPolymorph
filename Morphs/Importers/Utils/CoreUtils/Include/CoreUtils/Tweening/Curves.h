/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            //--------------------------------------------------------------------------------

            /// \brief Linear curve
            /// \image html linear.png
            class LinearCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quadratic ease in curve
            /// \image html QuadraticEaseIn.png
            class QuadraticEaseInCurve: public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quadratic ease out curve
            /// \image html QuadraticEaseOut.png
            class QuadraticEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quadratic ease in out curve
            /// \image html QuadraticEaseInOut.png
            class QuadraticEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Cubic ease in curve
            /// \image html CubicEaseIn.png
            class CubicEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Cubic ease out curve
            /// \image html CubicEaseOut.png
            class CubicEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Cubic ease in out curve
            /// \image html CubicEaseInOut.png
            class CubicEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quartic ease in curve
            /// \image html CubicEaseIn.png
            class QuarticEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quartic ease out curve
            /// \image html CubicEaseOut.png
            class QuarticEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Quartic ease in out curve
            /// \image html CubicEaseInOut.png
            class QuarticEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Exponential ease in curve
            /// \image html ExponentialEaseIn.png
            class ExponentialEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Exponential ease out curve
            /// \image html ExponentialEaseOut.png
            class ExponentialEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Exponential ease in out curve
            /// \image html ExponentialEaseInOut.png
            class ExponentialEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Sine ease in curve
            /// \image html SineEaseIn.png
            class SineEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Sine ease out curve
            /// \image html SineEaseOut.png
            class SineEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Sine ease in out curve
            /// \image html SineEaseInOut.png
            class SineEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Back ease in curve
            /// \image html BackEaseIn.png
            class BackEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief back ease out curve
            /// \image html BackEaseOut.png
            class BackEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief back ease in out curve
            /// \image html BackEaseInOut.png
            class BackEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Bounce ease in curve
            /// \image html BounceEaseIn.png
            class BounceEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Bounce ease out curve
            /// \image html BounceEaseOut.png
            class BounceEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Bounce ease in out curve
            /// \image html BounceEaseInOut.png
            class BounceEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Elastic ease in curve
            /// \image html ElasticEaseIn.png
            class ElasticEaseInCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Elastic ease out curve
            /// \image html ElasticEaseOut.png
            class ElasticEaseOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

            /// \brief Elastic ease in out curve
            /// \image html ElasticEaseInOut.png
            class ElasticEaseInOutCurve : public ICurve
            {
            public:
                virtual double Remap(double progress) const override;
            };

            //--------------------------------------------------------------------------------

        }// end Tweening
    }// end Utils
}// end Babylon
