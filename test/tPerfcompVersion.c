
/**
 * \file tPerfcompVersion.c
 * \date 2015
 */

#include "unittest.h"

#include <perfcomp/version.h>

TEST_FUNC( Version )
{
    TEST_TRUE( pfcmpMajorVersion() == 0 );
    TEST_TRUE( pfcmpMinorVersion() == 0 );
    TEST_TRUE( pfcmpPatchVersion() == 1 );
}

void SetupTests(void)
{
    REG_TEST( Version );
}
