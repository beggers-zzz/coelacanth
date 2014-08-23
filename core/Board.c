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

#include "Pieces.h"
#include "PieceTransform.h"


Board AllocateBoard() {
    Piece ps[64];

    ReadPieces(&INIT_BOARD_CHARS[0], &ps[0]);

    Board b = (Board) malloc(sizeof(BoardRec));
    if (b == NULL) {
        // shit
        return (Board) NULL;
    }

    b->whiteToMove = true;
    b->gameOver = false;
    b->enPassant = 0;
    b->promo = WhiteQueen;
    b->quietMoves = 0;
    b->moveStack = AllocateStack();
    // TODO: RoP hash

    memcpy(&b->bbs, &INIT_BOARD_BBREP, sizeof(b->bbs));
    memcpy(&b->pieces, &ps, sizeof(b->pieces));

    if (b->moveStack == NULL) {
        free(b);
        return NULL;
    }

    return b;
}


void FreeBoard(Board board) {
    FreeStack(board->moveStack);
    // TODO Free RoP hash
    free(board);
}


void SetPromochar(Board board, Piece piece) {
    board->promo = piece;
}


bool WhiteToMove(Board b) {
    return b->whiteToMove;
}

bool WhiteCastle(Board b) {
    //         king            a-rook         h-rook       virgin bits
    return (b->pieces[4] & (b->pieces[0] | b->pieces[7]) & VIRGIN_MASK);
}

bool BlackCastle(Board b) {
    return (b->pieces[60] & (b->pieces[54] | b->pieces[63]) & VIRGIN_MASK);
}

bool IsMoveLegal(Board board, int from, int to) {
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


bool MakeMove(Board b, int from, int to) {
    MoveStackNode sn;   

    if (!IsMoveLegal(b, from, to)) {
        return false;
    }

    sn.fromSquare = from;
    sn.toSquare = to;
    sn.takenPiece = b->pieces[to];
    sn.prevQuietCounter = b->quietMoves;
    sn.prevEnPassant = b->enPassant;
    PushStack(b->moveStack, sn);

    b->pieces[to] = b->pieces[from] & ~VIRGIN_MASK;
    b->pieces[from] = Empty;
    // TODO: BB changes and stuff
    // TODO: EP changes
    // TODO: Promotion
    // TODO: RoP hash
    // TODO: quiet move?
    b->whiteToMove = !(b->whiteToMove);

    return true;
}


void UnmakeMove(Board b) {
    MoveStackNode *sn;

    sn = PopStack(b->moveStack);

    b->enPassant = sn->prevEnPassant;
    b->quietMoves = sn->prevQuietCounter;
    b->pieces[sn->fromSquare] = b->pieces[sn->toSquare];
    b->pieces[sn->toSquare] = sn->takenPiece;

    b->whiteToMove = !(b->whiteToMove);
}


const Piece *GetArrayRep(Board board) {
    return board->pieces;
}


const bb_t *GetBBRep(Board board) {
    return board->bbs;
}


Board BoardCopy(Board b) {
    Board nb;

    nb = (Board) malloc(sizeof(BoardRec));
    if (nb == NULL) {
        return nb;
    }

    nb->whiteToMove = b->whiteToMove;
    nb->gameOver = b->gameOver;
    nb->enPassant = b->enPassant;
    nb->quietMoves = b->quietMoves;
    nb->promo = b->promo;

    nb->moveStack = StackCopy(b->moveStack);

    memcpy(&nb->bbs, &b->bbs, sizeof(nb->bbs));
    memcpy(&nb->pieces, &b->pieces, sizeof(nb->pieces));

    if (nb->moveStack == NULL) {
        free(nb);
    }

    return nb;
}


bool BoardEQ(Board b1, Board b2) {
    for (int i = 0; i < 12; i++) {
        if (b1->bbs[i] != b2->bbs[i]) {
            return false;
        }
    }

    return b1->whiteToMove == b2->whiteToMove &&
           b1->gameOver == b2->gameOver &&
           b1->enPassant == b2->enPassant &&
           b1->quietMoves == b2->quietMoves &&
           StackEQ(b1->moveStack, b2->moveStack);
}


void PrintBoard(Board board) {
    int i, j;
    char c[64];

    MakeBoardPrintable(GetArrayRep(board), &c[0]);

    for (i = 7; i >= 0; i--) {  // rows (backwards so black is printed above)
        for (j = 0; j < 8; j++) {  // cols
            printf("%c ", c[8*i + j]);
        }
        printf("\n");
    }
    printf("\n");
}

