/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Piece encoding tests.

*/

#include <check.h>

#include "Pieces.h"
#include "PieceTransform.h"
#include "PieceTransform_test.h"

#include "InitBoard.h"


static char _whitePawn = 'P';
static char _whiteKnight = 'N';
static char _whiteBishop = 'B';
static char _whiteRook = 'R';
static char _whiteQueen = 'Q';
static char _whiteKing = 'K';

static char _blackPawn = 'p';
static char _blackKnight = 'n';
static char _blackBishop = 'b';
static char _blackRook = 'r';
static char _blackQueen = 'q';
static char _blackKing = 'k';


START_TEST (ptc_wp) {
    ck_assert(PieceToChar(WhitePawn) == _whitePawn);
}
END_TEST

START_TEST (ptc_wn) {
    ck_assert(PieceToChar(WhiteKnight) == _whiteKnight);
}
END_TEST

START_TEST (ptc_wb) {
    ck_assert(PieceToChar(WhiteBishop) == _whiteBishop);
}
END_TEST

START_TEST (ptc_wr) {
    ck_assert(PieceToChar(WhiteRook) == _whiteRook);
}
END_TEST

START_TEST (ptc_wq) {
    ck_assert(PieceToChar(WhiteQueen) == _whiteQueen);
}
END_TEST

START_TEST (ptc_wk) {
    ck_assert(PieceToChar(WhiteKing) == _whiteKing);
}
END_TEST

START_TEST (ptc_bp) {
    ck_assert(PieceToChar(BlackPawn) == _blackPawn);
}
END_TEST

START_TEST (ptc_bn) {
    ck_assert(PieceToChar(BlackKnight) == _blackKnight);
}
END_TEST

START_TEST (ptc_bb) {
    ck_assert(PieceToChar(BlackBishop) == _blackBishop);
}
END_TEST

START_TEST (ptc_br) {
    ck_assert(PieceToChar(BlackRook) == _blackRook);
}
END_TEST

START_TEST (ptc_bq) {
    ck_assert(PieceToChar(BlackQueen) == _blackQueen);
}
END_TEST

START_TEST (ptc_bk) {
    ck_assert(PieceToChar(BlackKing) == _blackKing);
}
END_TEST

START_TEST (ctp_wp) {
    ck_assert(CharToPiece(_whitePawn) == WhitePawn);
}
END_TEST

START_TEST (ctp_wn) {
    ck_assert(CharToPiece(_whiteKnight) == WhiteKnight);
}
END_TEST

START_TEST (ctp_wb) {
    ck_assert(CharToPiece(_whiteBishop) == WhiteBishop);
}
END_TEST

START_TEST (ctp_wr) {
    ck_assert(CharToPiece(_whiteRook) == WhiteRook);
}
END_TEST

START_TEST (ctp_wq) {
    ck_assert(CharToPiece(_whiteQueen) == WhiteQueen);
}
END_TEST

START_TEST (ctp_wk) {
    ck_assert(CharToPiece(_whiteKing) == WhiteKing);
}
END_TEST

START_TEST (ctp_bp) {
    ck_assert(CharToPiece(_blackPawn) == BlackPawn);
}
END_TEST

START_TEST (ctp_bn) {
    ck_assert(CharToPiece(_blackKnight) == BlackKnight);
}
END_TEST

START_TEST (ctp_bb) {
    ck_assert(CharToPiece(_blackBishop) == BlackBishop);
}
END_TEST

START_TEST (ctp_br) {
    ck_assert(CharToPiece(_blackRook) == BlackRook);
}
END_TEST

START_TEST (ctp_bq) {
    ck_assert(CharToPiece(_blackQueen) == BlackQueen);
}
END_TEST

START_TEST (ctp_bk) {
    ck_assert(CharToPiece(_blackKing) == BlackKing);
}
END_TEST

START_TEST (arrays) {
    char c[64];
    Piece p[64];

    ReadPieces(INIT_BOARD_CHARS, p);
    MakeBoardPrintable(p, c);

    for (int i = 0; i < 64; i++) {
        ck_assert(c[i] == INIT_BOARD_CHARS[i]);
    }
}
END_TEST

START_TEST (virginity_empty_square) {
    Piece p;

    p = EmptySquare | VIRGIN_MASK;
    ck_assert(PieceToChar(p) == '.');
}
END_TEST

START_TEST (virginity_pawn) {
    Piece p;

    p = BlackPawn | VIRGIN_MASK;
    ck_assert(PieceToChar(p) == 'p');
}
END_TEST

START_TEST (virginity_king) {
    Piece p;

    p = WhiteKing | VIRGIN_MASK;
    ck_assert(PieceToChar(p) == 'K');
}
END_TEST

START_TEST (white_square) {
    Piece p;

    p = EmptySquare | WHITE_MASK;
    ck_assert(PieceToChar(p) == '.');
}
END_TEST

// Test suite
Suite *piecetransform_suite() {
    Suite *s = suite_create("Piece encoding");

    TCase *tc_ptc = tcase_create("PrettyPrint");
    TCase *tc_ctp = tcase_create("MakePiece");
    TCase *tc_arr = tcase_create("Arrays");
    TCase *tc_misc = tcase_create("Misc");

    // PieceToChar
    tcase_add_test(tc_ptc, ptc_wp);
    tcase_add_test(tc_ptc, ptc_wn);
    tcase_add_test(tc_ptc, ptc_wb);
    tcase_add_test(tc_ptc, ptc_wr);
    tcase_add_test(tc_ptc, ptc_wq);
    tcase_add_test(tc_ptc, ptc_wk);

    tcase_add_test(tc_ptc, ptc_bp);
    tcase_add_test(tc_ptc, ptc_bn);
    tcase_add_test(tc_ptc, ptc_bb);
    tcase_add_test(tc_ptc, ptc_br);
    tcase_add_test(tc_ptc, ptc_bq);
    tcase_add_test(tc_ptc, ptc_bk);

    // And CharToPiece
    tcase_add_test(tc_ctp, ctp_wp);
    tcase_add_test(tc_ctp, ctp_wn);
    tcase_add_test(tc_ctp, ctp_wb);
    tcase_add_test(tc_ctp, ctp_wr);
    tcase_add_test(tc_ctp, ctp_wq);
    tcase_add_test(tc_ctp, ctp_wk);

    tcase_add_test(tc_ctp, ctp_bp);
    tcase_add_test(tc_ctp, ctp_bn);
    tcase_add_test(tc_ctp, ctp_bb);
    tcase_add_test(tc_ctp, ctp_br);
    tcase_add_test(tc_ctp, ctp_bq);
    tcase_add_test(tc_ctp, ctp_bk);

    // Arrays
    tcase_add_test(tc_arr, arrays);

    // Stuff I'm too lazy to organize since it's a small test suite
    tcase_add_test(tc_misc, virginity_empty_square);
    tcase_add_test(tc_misc, virginity_pawn);
    tcase_add_test(tc_misc, virginity_king);
    tcase_add_test(tc_misc, white_square);

    suite_add_tcase(s, tc_ptc);
    suite_add_tcase(s, tc_ctp);
    suite_add_tcase(s, tc_arr);
    suite_add_tcase(s, tc_misc);

    return s;
}

