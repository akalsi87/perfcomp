/**
 * \file wall.c
 * \date 2015
 */

#include <perfcomp/time/wall.h>

pfWallTimePoint pfcmpCurrentWallTimePoint()
{
    pfWallTimePoint t = { 0.0 };
    return t;
}

pfWallTimePoint pfcmpAddWallTime(pfWallTimePoint a, pfWallTimePoint b)
{
    a.val += b.val;
    return a;
}

pfWallTimePoint pfcmpSubWallTime(pfWallTimePoint a, pfWallTimePoint b)
{
    a.val -= b.val;
    return a;
}

double pfcmpWallTimeToMicros(pfWallTimePoint a)
{
    return a.val;
}
