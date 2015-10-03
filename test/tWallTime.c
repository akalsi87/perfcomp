/**
 * \file tWallTime.c
 * \date 2015
 */

#include "unittest.h"

#include <perfcomp/time/wall.h>

TEST_FUNC( WallGet )
{
    pfWallTimePoint p = pfcmpCurrentWallTimePoint();
    TEST_TRUE( p.val == 0.0 );
}

TEST_FUNC( WallAddSub )
{
    pfWallTimePoint a = { 3.0 };
    pfWallTimePoint b = { 1.0 };

    pfWallTimePoint c;
    c = pfcmpAddWallTime(a, b);
    TEST_TRUE( c.val == 4.0 );

    c = pfcmpSubWallTime(a, b);
    TEST_TRUE( c.val == 2.0 );
}

void SetupTests(void)
{
    REG_TEST( WallGet );
    REG_TEST( WallAddSub );
}
