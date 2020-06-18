////////////////////////////////////////////////////////////////////////////////
// Copyright 2005 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef __JTK_SYS_MONITOR_HXX
#define __JTK_SYS_MONITOR_HXX

#include <JtTk/JtkStandard.h>
#include <time.h>

class JtkSysMonitor;

//#define JTKSYSMONITOR(x)
#define JTKSYSMONITOR(x) \
   { \
      if( JtkEnvironment::testOption( JtkEnvironment::JtkMEMORY_PROFILE_ENABLED, 1 ) ) \
      { \
         cerr << x << ", " \
         << ((double)JtkSysMonitor::getTime())/((double)CLOCKS_PER_SEC) << ", " \
         << JtkSysMonitor::getMemUsage() << ", " \
         << JtkSysMonitor::getPeakMemUsage() << ", " \
         << JtkSysMonitor::getVirtualMemUsage() << ", " \
         << JtkSysMonitor::getPeakVirtualMemUsage() << "\n"; \
      } \
   }

class JTK_TOOLKIT_API JtkSysMonitor
{
public:
   static long getMemUsage(int TakeInitSnap = 0);
   static long getPeakMemUsage();
   static long getVirtualMemUsage();
   static long getPeakVirtualMemUsage();
   static long getTime(int TakeInitSnap = 0);

private:
   static long _getMemUsage();
   static long _memSizeSnap;
   static long _timeSnap;
};

#endif

