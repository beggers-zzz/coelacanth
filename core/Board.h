/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

A Board represents the full state of the chess game.

*/

#ifndef _COELACANTH_BOARD_
#define _COELACANTH_BOARD_

#include <stdint.h>  // for uint64_t
#include <stdbool.h>

#include "BitBoard.h" // for bb_t

// Board positions
typedef struct boardPos {
    int     row;  // 1-8
    char    col;  // a-h
} Position;


// The Board itself.
struct boardRec;
typedef struct boardRec *Board;


// Allocate and return a new Board, in the standard starting position.
// Returns NULL on failure, the starting Board on success.
Board AllocateBoard();


// Free a Board.
//
// Arguments:
//
//  - board. The board to be freed.
void FreeBoard(Board board);


// Set the char to which promoted pawns should change. Defaults to queen, so
// you only need to call this if you plan on promoting a pawn to something
// other than a queen (or want a queen but just did a different promotion).
//
// Arguments:
//
//  - board. The board to set piece promotion on.
//  - piece. The piece that pawns should be promoted to.
void SetPromochar(Board board, char piece);


// Is it white's turn?
//
// Arguments:
//
//  - board. The Board we're examining.
//
// Returns true if it's white's turn, false if it's black's.
bool WhiteToMove(Board b);


// Check whether a move is legal, i.e. whether the piece at the first
// argument (a position) can be moved to the second argument (a position).
//
// Arguments:
//
//  - board. The board we're querying.
//  - from. The square we're trying to move from.
//  - to. The square we're moving to.
//
// Returns true if the move is possible, false otherwise (no piece at "from",
// either position is invalid, etc).
bool IsMoveLegal(Board board, Position from, Position to);


// Is the current position a soft draw? That is, have there been 50+ quiet
// moves in a row (no pawn pushes or captures of any sort) OR has the current
// position (including castling rights, etc) been repeated at least 2 times
// before?
//
// Arguments:
//
//  - board. The Board we're examining.
//
// Returns true if the Board is a soft draw.
bool BoardIsSoftDraw(Board b);


// Is the player to move in check?
//
// Arguments:
//
//  - board. The Board to examine.
//
// Returns true if the player to move is in check, false otherwise.
bool IsPlayerToMoveInCheck(Board b);


// Is the game over?
//
// Arguments:
//
//  - board. The Board we're examining.
//
// Returns true if the Board reperesents a game that is over, false otherwise.
bool IsGameOver(Board b);


// Who won the game? If this is called before the game is over, the return
// value is undefined.
//
// Arguments:
//
//  - board. The Board we're examining.
//
// Returns 1 if white won, 0 if it was a draw, -1 if black won. If the game
// is not over, behavior is undefined.
int WhoWon(Board b);


// Move a piece from one position to another.
//
// Arguments:
//
//  - board. The board we're moving on.
//  - from. the square we're trying to move from.
//  - to. The square we're moving to.
//
// Returns true if the move was made, false if not (because it was illegal).
bool MakeMove(Board board, Position from, Position to);


// Unmake a move. That is, mutate the passed Board such that it is exactly
// as it was before the most-recently made move. If you call this on the
// initial Board, the behavior is undefined.
//
// Arguments:
//
//  - board. The board to unmake a move on.
//
void UnmakeMove(Board b);


// Get an array of pieces representing the board. 
//
// Arguments:
//
//  - board. The board we're getting the array representation of.
//
// Returns the array representation of the passed board.
const char *GetArrayRep(Board board);


// Get the BitBoard representation of the Board.
//
// Arguments:
//
//  - board. The Board we're getting the representation of.
//
// Returns the bb_t[] representation of the Board.
const bb_t *GetBBRep(Board board);


// Copy the board. Does a deep copy, so not something you want to do often.
//
// Arguments:
//
//  - board. The Board we're copying.
//
// Returns a copy of the Board. That is, a Board such that BoardEQ(old, new) is
// true.
Board BoardCopy(Board b);


// Board equality. Returns true if the two passed Boards are equal, false
// otherwise.
//
// Arguments
//
//  - b1. The first Board.
//  - b2. The second Board.
//
// Returns true if the Boards are equal (observational equality, NOT behavioral
// or reference equality. So, after UnmakeMove() is called on each Board,
// they may no longer be equal).
bool BoardEQ(Board b1, Board b2);


// Print the board. Empty squares will be represented by "."
//
// Arguments:
//
//  - board. The Board to print.
void PrintBoard(Board board);


#endif // _COELACANTH_BOARD_
