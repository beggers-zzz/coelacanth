/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

This file contains the implementation of structs found in "Board.h".

*/

#ifndef _BEGGERS_BOARD_PRIV_
#define _BEGGERS_BOARD_PRIV_

#include <stdbool.h>

#include "./Board.h"             // for Board
#include "./static/globals.h"    // for bitrep_t

typedef struct boardRec {
    bool       whiteCastle;  // can white castle?
    bool       blackCastle;  // can black castle?
    int        enPassant;    // position of pawn that can currently en passant
    int        quietMoves;   // number of quiet moves made in a row
    char       promo;        // what should we promote pawns to?
    /* SOMETHING ABOUT REPETITION OF POSITION PL0X */
    bbrep_t    bbs;          // our bitboards
    char       pieces[64];   // our piece array
} BoardRec;


#endif  // _BEGGERS_BOARD_PRIV_
