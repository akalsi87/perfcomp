/**
 * \file cpu.h
 * \date 2015
 */

#ifndef PERFCOMP_TIME_CPU_H
#define PERFCOMP_TIME_CPU_H

#include <perfcomp/exportsym.h>

/*!
 * CPU time struct
 */
typedef struct {
    double val;
} pfCPUTimePoint;

PERFCOMP_API
/*!
 * Get the current CPU time point
 */
pfCPUTimePoint pfcmpCurrentCPUTimePoint();

PERFCOMP_API
/*!
 * Add two CPU time points.
 *
 * \return \c a + b
 */
pfCPUTimePoint pfcmpAddCPUTime(pfCPUTimePoint a, pfCPUTimePoint b);

PERFCOMP_API
/*!
 * Subtract two CPU time points.
 *
 * \return \c a - b
 */
pfCPUTimePoint pfcmpSubCPUTime(pfCPUTimePoint a, pfCPUTimePoint b);

PERFCOMP_API
/*!
 * To microseconds.
 *
 * \return \c a as microseconds
 */
double pfcmpCPUTimeToMicros(pfCPUTimePoint a);

#endif//PERFCOMP_TIME_CPU_H
