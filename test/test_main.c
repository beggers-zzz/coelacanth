/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Runs alllllllll the tests.

*/

#include <check.h>

#include "./util/util_tests.h"

int main(void) {
    int number_failed;

    Suite *s = movestack_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);  // for valgrind

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed;
}
