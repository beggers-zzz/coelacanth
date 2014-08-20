/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Tests the Board.

*/

#include <check.h>

#include "Board.h"
#include "Board_test.h"


// Fixtures
Board b;

void setup_b() {
    b = AllocateBoard();
}

void teardown_b() {
    FreeBoard(b);
}


// Tests
START_TEST (test_basic) {
    ck_assert(b != NULL);
}
END_TEST


Suite *board_suite() {
    Suite *s = suite_create("Board");

    // Base (just allocs and frees a board)
    TCase *tc_base = tcase_create("Base");
    tcase_add_checked_fixture(tc_base, setup_b, teardown_b);
    tcase_add_test(tc_base, test_basic);
    suite_add_tcase(s, tc_base);

    return s;
}
