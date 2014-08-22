/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Pieces.

*/

#include "Pieces.h"

const Piece EmptySquare = 0;
const Piece WhitePawn = PAWN_MASK | WHITE_MASK;
const Piece WhiteKnight = KNIGHT_MASK | WHITE_MASK;
const Piece WhiteBishop = BISHOP_MASK | WHITE_MASK;
const Piece WhiteRook = ROOK_MASK | WHITE_MASK;
const Piece WhiteQueen = QUEEN_MASK | WHITE_MASK;
const Piece WhiteKing = KING_MASK | WHITE_MASK;
const Piece BlackPawn = PAWN_MASK;
const Piece BlackKnight = KNIGHT_MASK;
const Piece BlackBishop = BISHOP_MASK;
const Piece BlackRook = ROOK_MASK;
const Piece BlackQueen = QUEEN_MASK;
const Piece BlackKing = KING_MASK;
