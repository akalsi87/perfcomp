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

