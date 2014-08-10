/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the board specification found in "Board.h".

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Board.h"
#include "Board_priv.h"


// Helper function to get a row from a Position
static int rfp(Position p);

// Helper function to get a col from a Position
static int cfp(Position p);


Board AllocateBoard() {
    Board b = (Board) malloc(sizeof(BoardRec));
    if (b == NULL) {
        // shit
        return (Board) NULL;
    }

    b->whiteCastle = true;
    b->blackCastle = true;
    b->enPassant = 0;
    b->promo = 0x50;
    b->pieces = [[0x08, 0x02, 0x04, 0x10, 0x20, 0x04, 0x02, 0x08]
                ,[0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01]
                ,[0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
                ,[0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
                ,[0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
                ,[0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
                ,[0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41]
                ,[0x48, 0x42, 0x44, 0x50, 0x60, 0x44, 0x42, 0x48]
                ]
    return b;
}


FreeBoard(Board board) {
    free(board);
}


Piece GetPiece(Board board, Position pos) {
    return board->pieces[rfp(pos)][cfp(pos)];
}


bool IsLegal(Board board, Position from, Position to) {
    return true;  // for now
}


void SetPromoPiece(Board board, Piece piece) {
    board->promo = piece;
}


void MakeMove(Board board, Position from, Position to) {
    b->pieces[rfp(to)][cfp(to)] = b->pieces[rfp(from)][cfp(from)];
    b->pieces[rfp(from)][cfp(from)] = 0;
}


Piece[][] GetPieces(Board board) {
    return board->pieces;
}


void PrintBoard(Board board) {
    Piece[][] ps;
    Piece p;
    char c;

    ps = board->pieces;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++ {
            p = ps[i][j];
            if (p & 0x01) {
                c = 'p';
            } else if (p & 0x02) {
                c = 'n';
            } else if (p & 0x04) {
                c = 'b';
            } else if (p & 0x08) {
                c = 'r';
            } else if (p & 0x10) {
                c = 'q';
            } else if (p & 0x20) {
                c = 'k';
            } else {
                c = '.';
            }

            if (p & 0x40) {
                c = c - 32;
            }

            printf("%c ", c);
        }
    }
}


static int rfp(Position p) {
    return 8 - pos.row;
}

static int cfp(Position p) {
    return p.col - 'a';
}
