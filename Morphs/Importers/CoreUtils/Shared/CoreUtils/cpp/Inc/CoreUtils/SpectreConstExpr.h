/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(SPECTRE_CONSTEXPR_H)
#define SPECTRE_CONSTEXPR_H

// Older compiler versions don't support constexpr as broadly, so don't use it in those contexts.
// Logic based on similar logic in DirectXMath (XM_CONST, XM_CONSTEXPR).
#if defined(_MSC_VER) && (_MSC_VER < 1910)
#define SPECTRE_CONST const
#define SPECTRE_CONSTEXPR
#else
#define SPECTRE_CONST constexpr
#define SPECTRE_CONSTEXPR constexpr
#endif

#endif // !defined(SPECTRE_CONSTEXPR_H)