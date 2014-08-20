/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Tests the MoveStack.

*/

#include <check.h>
#include <stdbool.h>

#include "MoveStack.h"
#include "MoveStack_test.h"


// Helpers to get a few different stack nodes
static StackNode getSN1();
static StackNode getSN2();
static StackNode getSN3();


// Fixtures

MoveStack s;

void setup(void) {
    s = AllocateStack();
}

void teardown(void) {
    FreeStack(s);
}

// And the tests themselves
START_TEST (test_free) {
    ck_assert(s != NULL);
}
END_TEST

START_TEST (test_push_one_size_one) {
    PushStack(s, getSN1());
    ck_assert_int_eq(StackSize(s), 1);
}
END_TEST

START_TEST (test_push_two_size_two) {
    PushStack(s, getSN1());
    PushStack(s, getSN2());
    ck_assert_int_eq(StackSize(s), 2);
}
END_TEST

START_TEST (test_push_pop_equal) {
    PushStack(s, getSN1());
    ck_assert(sneq(getSN1(), *PopStack(s)));
}
END_TEST

START_TEST (test_push_peek_pop_equal) {
    PushStack(s, getSN2());
    StackNode sn = *PeekStack(s);
    ck_assert(sneq(getSN2(), sn));
    ck_assert(sneq(sn, *PopStack(s)));
}
END_TEST

START_TEST (test_peek_idempotent) {
    PushStack(s, getSN3());
    StackNode sn = *PeekStack(s);
    for (int i = 0; i < 10; i++) {
        ck_assert(sneq(sn, *PeekStack(s)));
    }
}
END_TEST

START_TEST (test_size_idempotent) {
    PushStack(s, getSN3());
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(StackSize(s), 1);
    }
}
END_TEST

START_TEST (test_push_many_pop_last) {
    PushStack(s, getSN1());
    PushStack(s, getSN2());
    PushStack(s, getSN3());
    ck_assert(sneq(getSN3(), *PopStack(s)));
    ck_assert(sneq(getSN2(), *PopStack(s)));
    ck_assert(sneq(getSN1(), *PopStack(s)));
}
END_TEST

START_TEST (test_stack_copy_gives_equal) {
    MoveStack s2;

    PushStack(s, getSN3());

    s2 = StackCopy(s);
    ck_assert(sneq(*PopStack(s), *PopStack(s2)));

    FreeStack(s2);
}
END_TEST

START_TEST (test_stack_copy_equal_more_thorough) {
    MoveStack s2;

    PushStack(s, getSN3());
    PushStack(s, getSN1());
    PushStack(s, getSN2());

    s2 = StackCopy(s);

    ck_assert(sneq(*PeekStack(s), *PeekStack(s2)));
    ck_assert(sneq(*PopStack(s), *PopStack(s2)));
    ck_assert(sneq(*PeekStack(s), *PeekStack(s2)));
    ck_assert(sneq(*PopStack(s), *PopStack(s2)));
    ck_assert(sneq(*PeekStack(s), *PeekStack(s2)));
    ck_assert(sneq(*PopStack(s), *PopStack(s2)));

    FreeStack(s2);
}
END_TEST

START_TEST (test_stack_copy_different_stacks) {
    MoveStack s2;
    
    s2 = StackCopy(s);

    PopStack(s);

    ck_assert_int_ne(StackSize(s), StackSize(s2));

    FreeStack(s2);
}
END_TEST

// Our actual test suite
Suite *movestack_suite() {
    Suite *s = suite_create("MoveStack");

    TCase *tc_core = tcase_create("Core");
    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_free);
    tcase_add_test(tc_core, test_push_one_size_one);
    tcase_add_test(tc_core, test_push_two_size_two);
    tcase_add_test(tc_core, test_push_pop_equal);
    tcase_add_test(tc_core, test_push_peek_pop_equal);
    tcase_add_test(tc_core, test_push_many_pop_last);
    tcase_add_test(tc_core, test_peek_idempotent);
    tcase_add_test(tc_core, test_size_idempotent);
    tcase_add_test(tc_core, test_stack_copy_gives_equal);
    tcase_add_test(tc_core, test_stack_copy_equal_more_thorough);
    tcase_add_test(tc_core, test_stack_copy_different_stacks);

    suite_add_tcase(s, tc_core);

    return s;
}


// Helper functions

static StackNode getSN1() {
    StackNode sn;
    sn.fromSquare = 1;
    sn.toSquare = 2;
    sn.takenPiece = '.';
    sn.prevQuietCounter = 10;
    sn.prevEnPassant = -1;
    sn.wCastle = true;
    sn.bCastle = false;

    return sn;
}

static StackNode getSN2() {
    StackNode sn;
    sn.fromSquare = 2;
    sn.toSquare = 9;
    sn.takenPiece = 'k';
    sn.prevQuietCounter = 20;
    sn.prevEnPassant = -1;
    sn.wCastle = false;
    sn.bCastle = false;

    return sn;
}

static StackNode getSN3() {
    StackNode sn;
    sn.fromSquare = 10;
    sn.toSquare = 30;
    sn.takenPiece = 'Q';
    sn.prevQuietCounter = 45;
    sn.prevEnPassant = 25;
    sn.wCastle = false;
    sn.bCastle = true;

    return sn;
}

