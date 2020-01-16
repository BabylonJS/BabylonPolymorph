/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CanvasCll.h"

#if ENABLE_MACCLL_LIBRARY

#if CANVAS_PLATFORM_IS_MACOS()

///////////////////////////////////////////////////////////////////////////////
// MACOS Version of CanvasCllInitForPlatform
///////////////////////////////////////////////////////////////////////////////

#include "CanvasCllInit.h"
#include "CanvasCllLogger.h"
#include <cll/CllApi.h>
#include <cll/MacNetworkHandler.h>
#include <cll/MacPartA.h>
#include <boost/filesystem.hpp>
#import <Foundation/Foundation.h>

// This function was copied from the CLL Library Source 
// https://pandemonium.visualstudio.com/DefaultCollection/_git/CommonSchema?_a=contents&path=%2Fxplatcll%2FMac%2FSrc%2FMacCll.mm&version=GBcompactCore
path_string getPath(const string& iKey, shared_ptr<cll::ILogger> inLogger)
{
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString* cachePath = [paths objectAtIndex:0];
    
    boost::filesystem::path dataPath([cachePath UTF8String]);
    dataPath /= "CLL";
    dataPath /= iKey.data();
    
    inLogger->debug("cll::getPath", "Using path: " + dataPath.string());;
    
    return dataPath.string<path_string>();
}

// This is based on the function "initCllForTenant" in the CLL Library Source
// https://pandemonium.visualstudio.com/DefaultCollection/_git/CommonSchema?_a=contents&path=%2Fxplatcll%2FMac%2FSrc%2FMacCll.mm&version=GBcompactCore
int Spectre::Utils::CanvasCllInitForPlatform(const std::string& iKey)
{
    return cll::CllApi::init( shared_ptr<cll::ILogger>(new CanvasCllLogger(cll::ILogger::LevelDebug)),
                            getPath(iKey, shared_ptr<cll::ILogger>(new CanvasCllLogger(cll::ILogger::LevelDebug))),
                            cll::MacPartA(iKey),
                            shared_ptr<cll::INetworkHandler>(new cll::MacNetworkHandler()));
}

#else   // !CANVAS_PLATFORM_IS_MACOS

#include "CanvasCllInit.h"
#include <cll/iOSCll.h>

///////////////////////////////////////////////////////////////////////////////
// IOS Version of CanvasCllInitForPlatform
///////////////////////////////////////////////////////////////////////////////

int Spectre::Utils::CanvasCllInitForPlatform(const std::string& iKey)
{
    return cll::initCllForTenant(iKey);
}

#endif  // CANVAS_PLATFORM_IS_MACOS

#endif  // ENABLE_MACCLL_LIBRARY