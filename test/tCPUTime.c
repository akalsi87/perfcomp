
/**
 * \file tCPUTime.c
 * \date 2015
 */

#include "unittest.h"

#include <perfcomp/time/cpu.h>

TEST_FUNC( CPUGet )
{
    pfCPUTimePoint p = pfcmpCurrentCPUTimePoint();
    TEST_TRUE( &(p.val) );
}

TEST_FUNC( CPUAddSub )
{
    pfCPUTimePoint a = { 3.0 };
    pfCPUTimePoint b = { 1.0 };

    pfCPUTimePoint c;
    c = pfcmpAddCPUTime(a, b);
    TEST_TRUE( c.val == 4.0 );

    c = pfcmpSubCPUTime(a, b);
    TEST_TRUE( c.val == 2.0 );
}

void SetupTests(void)
{
    REG_TEST( CPUGet );
    REG_TEST( CPUAddSub );
}
