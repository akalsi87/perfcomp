# TEST: sub module

add_test_exe    (tPerfcompVersion tPerfcompVersion.c)
test_link_libs  (tPerfcompVersion perfcomp)
create_test     (tPerfcompVersion)


add_test_exe    (tWallTime tWallTime.c)
test_link_libs  (tWallTime perfcomp)
create_test     (tWallTime)


add_test_exe    (tCPUTime tCPUTime.c)
test_link_libs  (tCPUTime perfcomp)
create_test     (tCPUTime)

#
# Test against the static library
#
add_definitions("-DPERFCOMP_LINK_STATIC")

macro(copyrenamefile orig new)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${orig} ${CMAKE_CURRENT_SOURCE_DIR}/${new} COPYONLY)
endmacro()

copyrenamefile  (tPerfcompVersion.c tPerfcompVersion_s.c)
add_test_exe    (tPerfcompVersion_s tPerfcompVersion_s.c)
test_link_libs  (tPerfcompVersion_s perfcomp_s)
create_test     (tPerfcompVersion_s)


copyrenamefile  (tWallTime.c tWallTime_s.c)
add_test_exe    (tWallTime_s tWallTime_s.c)
test_link_libs  (tWallTime_s perfcomp_s)
create_test     (tWallTime_s)


copyrenamefile  (tCPUTime.c tCPUTime_s.c)
add_test_exe    (tCPUTime_s tCPUTime_s.c)
test_link_libs  (tCPUTime_s perfcomp_s)
create_test     (tCPUTime_s)

