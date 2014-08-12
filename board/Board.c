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
    b->promo = 0x50;
    Piece ini[64] = {0x08, 0x02, 0x04, 0x10, 0x20, 0x04, 0x02, 0x08,
                0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
                0x48, 0x42, 0x44, 0x50, 0x60, 0x44, 0x42, 0x48};

    memcpy(&b->pieces, &ini, sizeof(b->pieces));

    return b;
}


void FreeBoard(Board board) {
    free(board);
}


Piece GetPiece(Board board, Position pos) {
    return board->pieces[ifp(pos)];
}


bool IsLegal(Board board, Position from, Position to) {
    return true;  // for now
}


void SetPromoPiece(Board board, Piece piece) {
    board->promo = piece;
}


void MakeMove(Board b, Position from, Position to) {
    printf("%d(%c%d) -> %d(%c%d)\n", ifp(from), from.col, from.row, ifp(to), to.col, to.row);
    printf("Piece at from: %c\n", b->pieces[ifp(from)]);
    printf("Piece at to: %c\n", b->pieces[ifp(to)]);
    b->pieces[ifp(to)] = b->pieces[ifp(from)];
    b->pieces[ifp(from)] = 0;
}


Piece *GetPieces(Board board) {
    return board->pieces;
}


void PrintBoard(Board board) {
    Piece *ps;
    Piece p;
    char c;

    ps = board->pieces;
    for (int i = 0; i < 64; i++) {

        if (i % 8 == 0) {
            printf("\n");
        }

        p = ps[i];
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
    printf("\n");
}


static int ifp(Position p) {
    return 8*(8 - p.row) + (p.col - 'a');
}
