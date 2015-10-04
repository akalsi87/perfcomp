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
add_test_exe    (tPerfcompVersion_s tPerfcompVersion.c)
test_link_libs  (tPerfcompVersion_s perfcomp_s)
create_test     (tPerfcompVersion_s)


add_test_exe    (tWallTime_s tWallTime.c)
test_link_libs  (tWallTime_s perfcomp_s)
create_test     (tWallTime_s)


add_test_exe    (tCPUTime_s tCPUTime.c)
test_link_libs  (tCPUTime_s perfcomp_s)
create_test     (tCPUTime_s)

