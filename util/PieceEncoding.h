/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

How to get characters from pieces, and vice versa.

We encode pieces as 8 bits. 1 -> pawn, 2 -> knight, 4 -> bishop, 8 -> rook,
16 -> queen, 32 -> king, 64 -> white, 128 -> unmoved (used for castling rights
stuff).

*/

#ifndef _COELACANTH_PIECE_ENC_
#define _COELACANTH_PIECE_ENC_

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


// Nice-to-haves. Most interesting things we can do with Pieces should be done
// using bit-twiddling at the place they're needed -- I don't trust GCC to
// optimize away all the function calls.

// Get the standard character representation of the piece. (downcase for black).
char PrettyPiece(Piece p);

// Get a piece from a char.
Piece MakePiece(char c);

#endif // _COELACANTH_PIECE_ENC_
