/**
 * \file wall.c
 * \date 2015
 */

#include <perfcomp/time/wall.h>

#if defined(_MSC_VER)

#include <Windows.h>

double PCFreq()
{
    static double freq = -1.0;
    if (freq == -1.0) {
        LARGE_INTEGER li;
        QueryPerformanceFrequency(&li);
        freq = (double)(li.QuadPart);
    }
    return freq;
}

#define AS_LONG_LONG(x) *(LONGLONG*)(&(x))

void InitWallTimePoint(pfWallTimePoint* p)
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    AS_LONG_LONG(p->val) = li.QuadPart;
}

void InPlaceAddWallTime(pfWallTimePoint* pa, const pfWallTimePoint* pb)
{
    AS_LONG_LONG(pa->val) += AS_LONG_LONG(pb->val);
}

void InPlaceSubWallTime(pfWallTimePoint* pa, const pfWallTimePoint* pb)
{
    AS_LONG_LONG(pa->val) -= AS_LONG_LONG(pb->val);
}

void InPlaceWallToMicros(const pfWallTimePoint* p, double* val)
{
    *val = AS_LONG_LONG(p->val) / PCFreq();
    *val *= 1.0e6;
}

#else//UNIX

void InitWallTimePoint(pfWallTimePoint* p)
{
    p->val = 0;
}

void InPlaceAddWallTime(pfWallTimePoint* pa, const pfWallTimePoint* pb)
{
    pa->val += pb->val;
}

void InPlaceSubWallTime(pfWallTimePoint* pa, const pfWallTimePoint* pb)
{
    pa->val -= pb->val;
}

void InPlaceWallToMicros(const pfWallTimePoint* p, double* val)
{
    *val = p->val;
}

#endif//defined(_MSC_VER)

pfWallTimePoint pfcmpCurrentWallTimePoint()
{
    pfWallTimePoint t;
    InitWallTimePoint(&t);
    return t;
}

pfWallTimePoint pfcmpAddWallTime(pfWallTimePoint a, pfWallTimePoint b)
{
    InPlaceAddWallTime(&a, &b);
    return a;
}

pfWallTimePoint pfcmpSubWallTime(pfWallTimePoint a, pfWallTimePoint b)
{
    InPlaceSubWallTime(&a, &b);
    return a;
}

double pfcmpWallTimeToMicros(pfWallTimePoint a)
{
    double us;
    InPlaceWallToMicros(&a, &us);
    return us;
}
