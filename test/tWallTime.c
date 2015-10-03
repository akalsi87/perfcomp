/**
 * \file tWallTime.c
 * \date 2015
 */

#include "unittest.h"

#include <perfcomp/time/wall.h>

TEST_FUNC( WallGet )
{
    pfWallTimePoint p1 = pfcmpCurrentWallTimePoint();
    pfWallTimePoint p2 = pfcmpCurrentWallTimePoint();
    TEST_TRUE( p1.val <= p2.val );
    p2 = pfcmpSubWallTime(p2, p1);
    TEST_TRUE( pfcmpWallTimeToMicros(p2) >= 0.0 );
}

TEST_FUNC( WallAddSub )
{
    pfWallTimePoint b = pfcmpCurrentWallTimePoint();
    pfWallTimePoint a = pfcmpCurrentWallTimePoint();

    pfWallTimePoint c;
    c = pfcmpAddWallTime(a, b);
    TEST_TRUE( c.val > a.val );

    c = pfcmpSubWallTime(a, b);
    TEST_TRUE( c.val < a.val );
}

void SetupTests(void)
{
    REG_TEST( WallGet );
    REG_TEST( WallAddSub );
}
