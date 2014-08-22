/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Pieces are like, important.

*/

#ifndef _COELACANTH_PIECES_
#define _COELACANTH_PIECES_

#include <stdint.h>

typedef uint8_t Piece;

#define PAWN_MASK       0x01
#define KNIGHT_MASK     0x02
#define BISHOP_MASK     0x04
#define ROOK_MASK       0x08
#define QUEEN_MASK      0x10
#define KING_MASK       0x20
#define WHITE_MASK      0x40
#define VIRGIN_MASK     0x80

extern const Piece EmptySquare;
extern const Piece WhitePawn;
extern const Piece WhiteKnight;
extern const Piece WhiteBishop;
extern const Piece WhiteRook;
extern const Piece WhiteQueen;
extern const Piece WhiteKing;
extern const Piece BlackPawn;
extern const Piece BlackKnight;
extern const Piece BlackBishop;
extern const Piece BlackRook;
extern const Piece BlackQueen;
extern const Piece BlackKing;

#endif  // _COELACANTH_PIECES_
