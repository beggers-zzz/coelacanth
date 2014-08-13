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
#define wPawnBMap 0
#define bPawnBMap 1
#define wKnightBMap 2
#define bKnightBMap 3
#define wBishopBMap 4
#define bBishopBMap 5
#define wRookBMap 6
#define bRookBMap 7
#define wQueenBMap 8
#define bQueenBMap 9
#define wKingBMap 10
#define bKingBMap 11


#endif // _COELACANTH_BITBOARD_
