/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

This file contains the implementation of structs found in "Board.h".

*/

#ifndef _BEGGERS_BOARD_PRIV_
#define _BEGGERS_BOARD_PRIV_

#include "./Board.h"  // for Board
#include <stdbool.h>


typedef struct boardRec {
    bool        whiteCastle;  // can white castle?
    bool        blackCastle;  // can black castle?
    int         enPassant;    // position of pawn that can currently en passant
    int         quietMoves;   // number of quiet moves made in a row
    Piece       promo;        // what should we promote pawns to?
    Piece       pieces[64];   // all that other stuff
} BoardRec;


#endif  // _BEGGERS_BOARD_PRIV_
