/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <CoreUtils/SpectreSDK.h>
#include <functional>

namespace Spectre
{
    namespace Transcoder
    {
        /// \brief
        /// FractionalProgressCallback is the function signature for progress callbacks, where the float
        /// parameter represents the fractional progress from 0.0 to 1.0.
        ///
        /// SUGGESTED EXTENSION
        /// -------------------
        ///
        /// This should be extended to support the notion of sub-tasks / stages with decoupled progress. Stages
        /// should be:
        /// a) Not fixed at run time. Each importer/exporter may have different stages, so declaring a list
        ///    of stages by string seems appropriate
        /// b) Declared up-front, meaning that it's possible to display a meaningful sense of partial completeness
        ///
        /// For example:
        ///
        /// \verbatim
        /// Parsing OBJ:             97% [********* ]
        /// Consolidating vertices:   0% [          ]
        /// Fetching textures:       25% [**        ]
        /// \endverbatim
        using FractionalProgressCallback = std::function<void SPECTRESDK_CALL (float)>;
    }
}