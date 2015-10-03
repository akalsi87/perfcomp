/**
 * \file cpu.c
 * \date 2015
 */

#include <perfcomp/time/cpu.h>

pfCPUTimePoint pfcmpCurrentCPUTimePoint()
{
    pfCPUTimePoint t = { 0.0 };
    return t;
}

pfCPUTimePoint pfcmpAddCPUTime(pfCPUTimePoint a, pfCPUTimePoint b)
{
    a.val += b.val;
    return a;
}

pfCPUTimePoint pfcmpSubCPUTime(pfCPUTimePoint a, pfCPUTimePoint b)
{
    a.val -= b.val;
    return a;
}

double pfcmpCPUTimeToMicros(pfCPUTimePoint a)
{
    return a.val;
}
