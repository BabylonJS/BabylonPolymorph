/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if _MSC_VER >= 1700

// Support VS2012 SAL syntax only
#include <sal.h>

#else

#ifndef _In_
#define _In_
#endif  // _In_

#ifndef _In_z_
#define _In_z_
#endif  // _In_z_

#ifndef _In_opt_
#define _In_opt_
#endif  // _In_opt_

#ifndef _In_reads_
#define _In_reads_(x)
#endif  // _In_reads_

#ifndef _In_reads_bytes_
#define _In_reads_bytes_(x)
#endif  // _In_reads_bytes_

#ifndef __in_ecount
#define __in_ecount(x)
#endif  // __in_ecount

#ifndef _Out_
#define _Out_
#endif  // _Out_

#ifndef _Out_opt_
#define _Out_opt_
#endif  // _Out_opt_

#ifndef _Out_writes_
#define _Out_writes_(x)
#endif  // _Out_writes_

#ifndef _Out_writes_bytes_
#define _Out_writes_bytes_(x)
#endif  // _Out_writes_bytes_

#ifndef __out_ecount
#define __out_ecount(x)
#endif  // __out_ecount

#ifndef _Success_
#define _Success_(x)
#endif  // _Success_

#ifndef _Use_decl_annotations_
#define _Use_decl_annotations_
#endif  // _Use_decl_annotations_

#ifndef _Analysis_assume_
#define _Analysis_assume_(x)
#endif  // _Analysis_assume_

#ifndef __cpuid
#define __cpuid
#endif  // __cpuid

#ifndef _Printf_format_string_
#define _Printf_format_string_
#endif  // _Printf_format_string_

#endif
