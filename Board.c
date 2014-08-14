/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the board specification found in "Board.h".

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./Board.h"
#include "./Board_priv.h"
#include "./static/globals.h"


// Get the array index corresponding to the passed Position.
static int ifp(Position p);

Board AllocateBoard() {
    Board b = (Board) malloc(sizeof(BoardRec));
    if (b == NULL) {
        // shit
        return (Board) NULL;
    }

    b->whiteCastle = true;
    b->blackCastle = true;
    b->enPassant = 0;
    b->promo = 'q';
    b->quietMoves = 0;
    // TODO: RoP hash

    memcpy(&b->bbs, &INIT_BOARD_BBREP, 12 * sizeof(bb_t));
    memcpy(&b->pieces, &INIT_BOARD_A, sizeof(b->pieces));

    return b;
}


void FreeBoard(Board board) {
    free(board);
}


char GetPiece(Board board, Position pos) {
    return board->pieces[ifp(pos)];
}


bool IsMoveLegal(Board board, Position from, Position to) {
    return true;  // for now
    // TODO: Make sure we're not moving onto our own piece
    //       Make sure that's how we can move
    //       Check if we'd be in check
}


void SetPromochar(Board board, char piece) {
    board->promo = piece;
}


bool MakeMove(Board b, Position from, Position to) {
    if (!IsMoveLegal(b, from, to)) {
        return false;
    }

    b->pieces[ifp(to)] = b->pieces[ifp(from)];
    b->pieces[ifp(from)] = '.';
    // TODO: BB changes and stuff
    // TODO: Castling rights changes
    // TODO: EP changes
    // TODO: Promotion
    // TODO: RoP hash
    // TODO: quiet move?
    return true;
}


const char *GetArrayRep(Board board) {
    return board->pieces;
}

const bb_t *GetBBRep(Board board) {
    return board->bbs;
}

void PrintBoard(Board board) {
    char *ps;
    Position p;
    int i;
    char j;

    ps = board->pieces;
    for (i = 8; i > 0; i--) {
        for (j = 'a'; j <= 'h'; j++) {
            p.row = i;
            p.col = j;
            printf("%c ", ps[ifp(p)]);
        }
        printf("\n");
    }
    printf("\n");
}


static int ifp(Position p) {
    return 8*(p.row - 1) + (p.col - 'a');
}
