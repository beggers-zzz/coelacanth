/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

*/

#include <stdint.h>

#include "PieceTransform.h"
#include "Pieces.h"

char PieceToChar(Piece p) {
    char res;

    if (p & PAWN_MASK) {
        res = 'p';
    } else if (p & KNIGHT_MASK) {
        res = 'n';
    } else if (p & BISHOP_MASK) {
        res = 'b';
    } else if (p & ROOK_MASK) {
        res = 'r';
    } else if (p & QUEEN_MASK) {
        res = 'q';
    } else if (p & KING_MASK) {
        res = 'k';
    } else {
        // this shouldn't happen
        res = '.';
    }

    if (p & WHITE_MASK) {
        res -= 32;  // uppercase
    }

    return res;
}

Piece CharToPiece(char c) {
    uint8_t typemask;
    uint8_t wmask = 0;

    if (65 <= c && c <= 90) {
        // It's uppercase
        wmask = WHITE_MASK;
        c += 32;
    }

    if (c == 'p') {
        typemask = PAWN_MASK;
    } else if (c == 'n') {
        typemask = KNIGHT_MASK;
    } else if (c == 'b') {
        typemask = BISHOP_MASK;
    } else if (c == 'r') {
        typemask = ROOK_MASK;
    } else if (c == 'q') {
        typemask = QUEEN_MASK;
    } else if (c == 'k') {
        typemask = KING_MASK;
    } else {
        // They gave us some random crap
        typemask = 0;
    }

    return typemask | wmask;
}
