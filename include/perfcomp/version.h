/**
 * \file version.h
 * \date 2015
 */

#ifndef PERFCOMP_VERSION_H
#define PERFCOMP_VERSION_H

#include <perfcomp/builddef.h>

PERFCOMP_API
/*!
 * Return the major version of perfcomp
 */
int pfcmpMajorVersion();

PERFCOMP_API
/*!
 * Return the minor version of perfcomp
 */
int pfcmpMinorVersion();

PERFCOMP_API
/*!
 * Return the patch version of perfcomp
 */
int pfcmpPatchVersion();

#endif//PERFCOMP_VERSION_H
