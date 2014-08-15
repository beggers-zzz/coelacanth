/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Tests the MoveStack.

*/

#include <check.h>

#include "../../util/MoveStack.h"

START_TEST (test_movestack_alloc) {
    MoveStack s = AllocateStack();
    ck_assert(s != NULL);
}
END_TEST

Suite *movestack_suite() {
    Suite *s = suite_create("MoveStack");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_movestack_alloc);
    suite_add_tcase(s, tc_core);

    return s;
}

