/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Contains the bitboard and other relevant declarations.

*/

#ifndef _COELACANTH_BITBOARD_
#define _COELACANTH_BITBOARD_

#include <stdint.h>  // for uint64_t

typedef uint64_t bb_t;  // just a bitboard
typedef bb_t bbrep_t[12];  // full board rep

// Array indices for bitboards
#define wPawn 0
#define bPawn 1
#define wKnight 2
#define bKnight 3
#define wBishop 4
#define bBishop 5
#define wRook 6
#define bRook 7
#define wQueen 8
#define bQueen 9
#define wKing 10
#define bKing 11


#endif // _COELACANTH_BITBOARD_
