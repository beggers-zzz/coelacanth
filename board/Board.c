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
#include "../static/globals.h"


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

    memcpy(&b->pieces, &INIT_BOARD, sizeof(b->pieces));

    return b;
}


void FreeBoard(Board board) {
    free(board);
}


char Getchar(Board board, Position pos) {
    return board->pieces[ifp(pos)];
}


bool IsMoveLegal(Board board, Position from, Position to) {
    return from.col >= 'a' && from.col <= 'h' &&
            to.col >= 'a' && to.col <= 'h';
}


void SetPromochar(Board board, char piece) {
    board->promo = piece;
}


void MakeMove(Board b, Position from, Position to) {
    b->pieces[ifp(to)] = b->pieces[ifp(from)];
    b->pieces[ifp(from)] = '.';
}


char *Getchars(Board board) {
    return board->pieces;
}


void PrintBoard(Board board) {
    char *ps;
    int i;

    ps = board->pieces;
    for (i = 0; i < 64; i++) {

        if (i % 8 == 0) {
            printf("\n");
        }

        printf("%c ", ps[i]);

    }
    printf("\n");
}


static int ifp(Position p) {
    return 8*(8 - p.row) + (p.col - 'a');
}
