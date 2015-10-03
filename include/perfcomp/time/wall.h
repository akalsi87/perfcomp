/**
 * \file wall.h
 * \date 2015
 */

#ifndef PERFCOMP_TIME_WALL_H
#define PERFCOMP_TIME_WALL_H

#include <perfcomp/builddef.h>

/*!
 * Wall time struct
 */
typedef struct {
    double val;
} pfWallTimePoint;

PERFCOMP_API
/*!
 * Get the current wall time point
 */
pfWallTimePoint pfcmpCurrentWallTimePoint();

PERFCOMP_API
/*!
 * Add two wall time points.
 *
 * \return \c a + b
 */
pfWallTimePoint pfcmpAddWallTime(pfWallTimePoint a, pfWallTimePoint b);

PERFCOMP_API
/*!
 * Subtract two wall time points.
 *
 * \return \c a - b
 */
pfWallTimePoint pfcmpSubWallTime(pfWallTimePoint a, pfWallTimePoint b);

PERFCOMP_API
/*!
 * To microseconds.
 *
 * \return \c a as microseconds
 */
double pfcmpWallTimeToMicros(pfWallTimePoint a);

#endif//PERFCOMP_TIME_WALL_H
