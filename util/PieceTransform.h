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

// Read 64 Pieces from p, turn them to chars, and put them in c
void MakeBoardPrintable(Piece *p, char *c);

// Read 64 chars from c, turn them to Pieces, and put them in p
void ReadPieces(char *c, Piece *p);

#endif // _COELACANTH_PIECE_TRANSFORM_
