/********************************************************
 *                                                       *
 *   Copyright (C) Microsoft. All rights reserved.       *
 *                                                       *
 ********************************************************/

#include <FrameworkPch.h>
#include <unistd.h>
#include "Framework/PerformanceLoggingProviders.h"

//-------------------------------------------------------------------------------------------------

uint64_t Spectre::Utils::DefaultMemoryStatsProvider::GetTotalPhysicalMemory() const
{
    uint64_t pages = sysconf(_SC_PHYS_PAGES);
    uint64_t page_size = sysconf(_SC_PAGESIZE);
    return (pages * page_size);
}

//-------------------------------------------------------------------------------------------------

uint64_t Spectre::Utils::DefaultMemoryStatsProvider::GetCommitedMemory() const
{
    throw std::logic_error("Not implemented yet");
}

//-------------------------------------------------------------------------------------------------

uint64_t Spectre::Utils::DefaultMemoryStatsProvider::GetCurrentlyUsedMemory() const
{
    throw std::logic_error("Not implemented yet");
}


