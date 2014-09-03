/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

*/

#include <stdint.h>

#include "Board.h"
#include "_Zob.h"

static int GetPieceZobIndex(Piece p, int pos);

void ZobristInit(Board b) {
    srand(1229689);  // my student ID number
    for (int i = 0; i < 781; i++) {  // see Board_priv.h
        b->zobs[i] = ((uint64_t) rand() << 32) | rand();  // necessary for 64 bits
    }
    b->zobs[781] = 0;  // Empty square (XORing is faster than conditionals)
}


uint64_t ZobristEntireBoard(Board b) {
    uint64_t hash = 0;
    const Piece *ps = GetArrayRep(b);

    // First the pieces
    for (int i = 0; i < 64; i++) {
        hash ^= b->zobs[GetPieceZobIndex(ps[i], i)];
    }

    // Now the castling rights
    if (WhiteCastleKingsSide(b)) {
        hash ^= b->zobs[12 * 64];
    }
    if (WhiteCastleQueensSide(b)) {
        hash ^= b->zobs[12 * 64 + 1];
    }
    if (BlackCastleKingsSide(b)) {
        hash ^= b->zobs[12 * 64 + 2];
    }
    if (BlackCastleQueensSide(b)) {
        hash ^= b->zobs[12 * 64 + 3];
    }

    // And en passant
    if (EnPassantPawn(b) != -1) {
        hash ^= b->zobs[11 * 64 + 3 + EnPassantPawn(b)];
    }

    // And whose turn it is
    if (WhiteToMove(b)) {
        hash ^= b->zobs[780];
    }

    return hash;
}


static int GetPieceZobIndex(Piece p, int pos) {
    int index;

    if (p & PAWN_MASK) {
        index = 6 * 64;
    } else if (p & KNIGHT_MASK) {
        index = 7 * 64;
    } else if (p & BISHOP_MASK) {
        index = 8 * 64;
    } else if (p & ROOK_MASK) {
        index = 9 * 64;
    } else if (p & QUEEN_MASK) {
        index = 10 * 64;
    } else if (p & KING_MASK) {
        index = 11 * 64;
    } else {
        // Empty square
        return 781;
    }

    if (p & WHITE_MASK) {
        index -= 6 * 64;
    }

    return index + pos;
}

