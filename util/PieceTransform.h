/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

How to get characters from pieces, and vice versa.

We encode pieces as 8 bits. 1 -> pawn, 2 -> knight, 4 -> bishop, 8 -> rook,
16 -> queen, 32 -> king, 64 -> white, 128 -> unmoved (used for castling rights
stuff).

*/

#ifndef _COELACANTH_PIECE_TRANSFORM_
#define _COELACANTH_PIECE_TRANSFORM_

#include <stdint.h>
#include "Pieces.h"

// Get the standard character representation of the piece. (downcase for black).
char PieceToChar(Piece p);

// Get a piece from a char.
Piece CharToPiece(char c);

#endif // _COELACANTH_PIECE_TRANSFORM_
