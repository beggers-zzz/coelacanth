/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the board specification found in "Board.h".

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Board.h"
#include "Board_priv.h"
#include "BitBoard.h"
#include "InitBoard.h"
#include "MoveStack.h"


// Get the array index corresponding to the passed Position.
static int ifp(Position p);

Board AllocateBoard() {
    Board b = (Board) malloc(sizeof(BoardRec));
    if (b == NULL) {
        // shit
        return (Board) NULL;
    }

    b->whiteToMove = true;
    b->gameOver = false;
    b->whiteCastle = true;
    b->blackCastle = true;
    b->enPassant = 0;
    b->promo = 'q';
    b->quietMoves = 0;
    b->moveStack = AllocateStack();
    // TODO: RoP hash

    memcpy(&b->bbs, &INIT_BOARD_BBREP, sizeof(b->bbs));
    memcpy(&b->pieces, &INIT_BOARD_A, sizeof(b->pieces));

    return b;
}


void FreeBoard(Board board) {
    FreeStack(board->moveStack);
    // TODO Free RoP hash
    free(board);
}


void SetPromochar(Board board, char piece) {
    board->promo = piece;
}


bool WhiteToMove(Board b) {
    return b->whiteToMove;
}


bool IsMoveLegal(Board board, Position from, Position to) {
    if (from.row < 1 || to.row < 1 ||
        from.row > 8 || to.row > 8 ||
        from.col < 'a' || to.col < 'a' ||
        from.col > 'h' || to.col > 'h') {
        return false;
    }
    // TODO: Make sure we're not moving onto our own piece
    //       Make sure that's how we can move
    //       Check if we'd be in check
    return true;
}


bool BoardIsSoftDraw(Board b) {
    // TODO
    return false;
}


bool IsPlayerToMoveInCheck(Board b) {
    // TODO
    return false;
}


bool IsGameOver(Board b) {
    return b->gameOver;
}


int WhoWon(Board b) {
    // TODO
    return 1;
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
    b->whiteToMove = !(b->whiteToMove);
    return true;
}


void UnmakeMove(Board b) {
    // TODO
    b->whiteToMove = !(b->whiteToMove);
}


const char *GetArrayRep(Board board) {
    return board->pieces;
}


const bb_t *GetBBRep(Board board) {
    return board->bbs;
}


Board BoardCopy(Board b) {
    Board nb;

    nb = AllocateBoard();
    if (nb == NULL) {
        return nb;
    }

    nb->whiteToMove = b->whiteToMove;
    nb->whiteCastle = b->whiteCastle;
    nb->blackCastle = b->blackCastle;
    nb->gameOver = b->gameOver;
    nb->enPassant = b->enPassant;
    nb->quietMoves = b->quietMoves;
    nb->promo = b->promo;

    nb->moveStack = StackCopy(b->moveStack);

    memcpy(&nb->bbs, &b->bbs, sizeof(nb->bbs));
    memcpy(&nb->pieces, &b->pieces, sizeof(nb->pieces));

    return nb;
}


bool BoardEQ(Board b1, Board b2) {
    for (int i = 0; i < 12; i++) {
        if (b1->bbs[i] != b2->bbs[i]) {
            return false;
        }
    }

    return b1->whiteToMove == b2->whiteToMove &&
           b1->whiteCastle == b2->whiteCastle &&
           b1->blackCastle == b2->blackCastle &&
           b1->gameOver == b2->gameOver &&
           b1->enPassant == b2->enPassant &&
           b1->quietMoves == b2->quietMoves &&
           StackEQ(b1->moveStack, b2->moveStack);
}


void PrintBoard(Board board) {
    char *ps;
    Position p;
    int i;
    char j;

    printf("\n");

    ps = board->pieces;
    for (i = 8; i > 0; i--) {
        for (j = 'a'; j <= 'h'; j++) {
            p.row = i;
            p.col = j;
            printf("%c ", ps[ifp(p)]);
        }
        printf("\n");
    }
}


static int ifp(Position p) {
    return 8*(p.row - 1) + (p.col - 'a');
}
