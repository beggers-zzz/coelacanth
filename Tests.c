/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Runs alllllllll the tests.

*/

#include <check.h>

#include "MoveStack_test.h"
#include "Board_test.h"

int main(void) {
    int number_failed;
    SRunner *sr;

    sr = srunner_create(movestack_suite());
    srunner_add_suite(sr, board_suite());

    srunner_set_fork_status(sr, CK_NOFORK);  // for valgrind
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return number_failed;
}
