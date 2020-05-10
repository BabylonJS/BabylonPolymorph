/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(Babylon_CONSTEXPR_H)
#define Babylon_CONSTEXPR_H

// Older compiler versions don't support constexpr as broadly, so don't use it in those contexts.
// Logic based on similar logic in DirectXMath (XM_CONST, XM_CONSTEXPR).
#if defined(_MSC_VER) && (_MSC_VER < 1910)
#define Babylon_CONST const
#define Babylon_CONSTEXPR
#else
#define Babylon_CONST constexpr
#define Babylon_CONSTEXPR constexpr
#endif

#endif // !defined(Babylon_CONSTEXPR_H)
