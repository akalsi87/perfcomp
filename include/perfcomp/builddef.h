/**
 * \file builddef.h
 * \date 2015
 */

#ifndef PERFCOMP_BUILDDEF_H
#define PERFCOMP_BUILDDEF_H

/*!
 * Build definition for perfcomp 
 */
 
#if defined(PERFCOMP_BUILD)
#  if defined(_WIN32)
#    define PERFCOMP_API __declspec(dllexport)
#  else
#    define PERFCOMP_API __attribute__((__visibility__("default")))
#  endif
#else
#  if defined(_WIN32)   
#    define PERFCOMP_API __declspec(dllimport)
#  else
#    define PERFCOMP_API
#  endif
#endif

#endif//PERFCOMP_BUILDDEF_H
