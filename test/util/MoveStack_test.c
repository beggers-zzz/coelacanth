/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Tests the MoveStack.

*/

#include <check.h>
#include <stdbool.h>

#include "./util_tests.h"
#include "../../util/MoveStack.h"


// Helpers to get a few different stack nodes
static stackNode getSN1();
static stackNode getSN2();
static stackNode getSN3();
static bool sneq(stackNode s1, stackNode s2);


// The tests

START_TEST (test_free) {
    MoveStack s = AllocateStack();
    ck_assert(s != NULL);
    FreeStack(s);
}
END_TEST

START_TEST (test_push_one_size_one) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN1());
    ck_assert_int_eq(StackSize(s), 1);
    FreeStack(s);
}
END_TEST

START_TEST (test_push_two_size_two) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN1());
    PushStack(s, getSN2());
    ck_assert_int_eq(StackSize(s), 2);
    FreeStack(s);
}
END_TEST

START_TEST (test_push_pop_equal) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN1());
    ck_assert(sneq(getSN1(), *PopStack(s)));
    FreeStack(s);
}
END_TEST

START_TEST (test_push_peek_pop_equal) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN2());
    stackNode sn = *PeekStack(s);
    ck_assert(sneq(getSN2(), sn));
    ck_assert(sneq(sn, *PopStack(s)));
    FreeStack(s);
}
END_TEST

START_TEST (test_peek_idempotent) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN3());
    stackNode sn = *PeekStack(s);
    for (int i = 0; i < 10; i++) {
        ck_assert(sneq(sn, *PeekStack(s)));
    }
    FreeStack(s);
}
END_TEST

START_TEST (test_size_idempotent) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN3());
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(StackSize(s), 1);
    }
    FreeStack(s);
}
END_TEST

START_TEST (test_push_many_pop_last) {
    MoveStack s = AllocateStack();
    PushStack(s, getSN1());
    PushStack(s, getSN2());
    PushStack(s, getSN3());
    ck_assert(sneq(getSN3(), *PopStack(s)));
    ck_assert(sneq(getSN2(), *PopStack(s)));
    ck_assert(sneq(getSN1(), *PopStack(s)));
    FreeStack(s);
}
END_TEST


// Our actual test suite
Suite *movestack_suite() {
    Suite *s = suite_create("MoveStack");

    TCase *tc_core = tcase_create("Core");
    suite_add_tcase(s, tc_core);

    tcase_add_test(tc_core, test_free);
    tcase_add_test(tc_core, test_push_one_size_one);
    tcase_add_test(tc_core, test_push_two_size_two);
    tcase_add_test(tc_core, test_push_pop_equal);
    tcase_add_test(tc_core, test_push_peek_pop_equal);
    tcase_add_test(tc_core, test_push_many_pop_last);
    tcase_add_test(tc_core, test_peek_idempotent);
    tcase_add_test(tc_core, test_size_idempotent);

    return s;
}


// Helper functions

static stackNode getSN1() {
    stackNode sn;
    sn.fromSquare = 1;
    sn.toSquare = 2;
    sn.takenPiece = '.';
    sn.prevQuietCounter = 10;
    sn.prevEnPassant = -1;
    sn.whiteCastleChanged = true;
    sn.blackCastleChanged = false;

    return sn;
}

static stackNode getSN2() {
    stackNode sn;
    sn.fromSquare = 2;
    sn.toSquare = 9;
    sn.takenPiece = 'k';
    sn.prevQuietCounter = 20;
    sn.prevEnPassant = -1;
    sn.whiteCastleChanged = false;
    sn.blackCastleChanged = false;

    return sn;
}

static stackNode getSN3() {
    stackNode sn;
    sn.fromSquare = 10;
    sn.toSquare = 30;
    sn.takenPiece = 'Q';
    sn.prevQuietCounter = 45;
    sn.prevEnPassant = 25;
    sn.whiteCastleChanged = false;
    sn.blackCastleChanged = true;

    return sn;
}

static bool sneq(stackNode s1, stackNode s2) {
    return s1.fromSquare == s2.fromSquare &&
           s1.toSquare == s2.toSquare &&
           s1.takenPiece == s2.takenPiece &&
           s1.prevQuietCounter == s2.prevQuietCounter &&
           s1.prevEnPassant == s2.prevEnPassant &&
           s1.whiteCastleChanged == s2.whiteCastleChanged &&
           s1.blackCastleChanged == s2.blackCastleChanged;
}
 
