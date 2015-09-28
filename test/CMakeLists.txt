# TEST: sub module

add_test_exe    (tPerfcompVersion tPerfcompVersion.c)
test_link_libs  (tPerfcompVersion perfcomp)
create_test     (tPerfcompVersion)

