/**
 * \file cpu.c
 * \date 2015
 */

#include <perfcomp/time/cpu.h>

#if defined(_MSC_VER)

#include <Windows.h>

static void InitCPUTimePoint(pfCPUTimePoint* p)
{
    p->val = 0.0;
}

static void InPlaceAddCPUTime(pfCPUTimePoint* pa, const pfCPUTimePoint* pb)
{
    pa->val += pb->val;
}

static void InPlaceSubCPUTime(pfCPUTimePoint* pa, const pfCPUTimePoint* pb)
{
    pa->val -= pb->val;
}

static void InPlaceCPUToMicros(const pfCPUTimePoint* p, double* val)
{
    *val = p->val;
}

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))

#include <unistd.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>

static void InitCPUTimePoint(pfCPUTimePoint* p)
{
    p->val = 0.0;
}

static void InPlaceAddCPUTime(pfCPUTimePoint* pa, const pfCPUTimePoint* pb)
{
    pa->val += pb->val;
}

static void InPlaceSubCPUTime(pfCPUTimePoint* pa, const pfCPUTimePoint* pb)
{
    pa->val -= pb->val;
}

static void InPlaceCPUToMicros(const pfCPUTimePoint* p, double* val)
{
    *val = p->val;
}

#endif//defined(_MSC_VER)

pfCPUTimePoint pfcmpCurrentCPUTimePoint()
{
    pfCPUTimePoint t;
    InitCPUTimePoint(&t);
    return t;
}

pfCPUTimePoint pfcmpAddCPUTime(pfCPUTimePoint a, pfCPUTimePoint b)
{
    InPlaceAddCPUTime(&a, &b);
    return a;
}

pfCPUTimePoint pfcmpSubCPUTime(pfCPUTimePoint a, pfCPUTimePoint b)
{
    InPlaceSubCPUTime(&a, &b);
    return a;
}

double pfcmpCPUTimeToMicros(pfCPUTimePoint a)
{
    double us;
    InPlaceCPUToMicros(&a, &us);
    return us;
}
