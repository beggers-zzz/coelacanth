/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

This file contains the implementation of structs found in "Board.h".

*/

#ifndef _COELACANTH_BOARD_PRIV_
#define _COELACANTH_BOARD_PRIV_

#include <stdbool.h>
#include <stdint.h>

#include "Board.h"             // for Board
#include "BitBoard.h"          // for bitrep_t
#include "MoveStack.h"
#include "Pieces.h"

typedef struct boardRec {
    bool       whiteToMove;
    bool       gameOver;
    int        enPassant;    // position of pawn that can currently en passant
    int        quietMoves;   // number of quiet moves made in a row
    Piece      promo;        // what should we promote pawns to?
    MoveStack  moveStack;
    // TODO: RoP hash
    bb_t       bbs[12];      // our bitboards
    Piece      pieces[64];   // our piece array
} BoardRec;


#endif  // _COELACANTH_BOARD_PRIV_
