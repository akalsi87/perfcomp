# project

cmake_minimum_required(VERSION 3.0)

set(CPACK_PACKAGE_VERSION "0.1.1")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_PACKAGE_CONTACT )

set(PROJ_LICENSE_FILE COPYING)
set(PROJ_README_FILE  README.txt)

# -- Include the tests in the bin folder?
set(INCLUDE_TEST_IN_BIN FALSE)

# -- Set project name
project(perfcomp)

# -- Include the magic ProjTools
include("cmake/ProjTools.cmake")

# -- Add the subdirectories
set(PROJ_SUBDIRS  unittest; doc; tools; test)

# add all subdirs
foreach(subdir ${PROJ_SUBDIRS})
  add_subdirectory(${subdir})
endforeach(subdir)

###############
# libperfcomp #
###############

# -- build

set(perfcomp_maj_ver 0)
set(perfcomp_min_ver 0)
set(perfcomp_pat_ver 1)

set(perfcomp_lib_ver
    "${perfcomp_maj_ver}.${perfcomp_min_ver}.${perfcomp_pat_ver}")

set(perfcomp_lib_compat_ver
    "${perfcomp_maj_ver}.${perfcomp_min_ver}")

set(perfcomp_exp_hdr 
    include/perfcomp/builddef.h;
    include/perfcomp/version.h)

set(perfcomp_int_hdr )

set(perfcomp_src
    src/version.c)

add_lib(perfcomp SHARED ${perfcomp_src} ${perfcomp_int_hdr} ${perfcomp_exp_hdr})
add_lib_build_def(perfcomp PERFCOMP_BUILD)
add_comp_def(perfcomp PERFCOMP_MAJ=${perfcomp_maj_ver})
add_comp_def(perfcomp PERFCOMP_MIN=${perfcomp_min_ver})
add_comp_def(perfcomp PERFCOMP_PAT=${perfcomp_pat_ver})
link_libs(perfcomp )
set_tgt_ver(perfcomp ${perfcomp_lib_ver} ${perfcomp_lib_compat_ver})

# -- install

install_hdr(${perfcomp_exp_hdr})
install_tgt(perfcomp)
