/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

A Board represents the full state of the chess game.

*/

#ifndef _BEGGERS_BOARD_
#define _BEGGERS_BOARD_

#include <stdint.h>  // for uint64_t
#include <stdbool.h>


// Piece representation -- 8 bits. 1 is a pawn, 2 a knight, 4 a bishop,
// 8 a rook, 16 a queen, and 32 a king. The second-highest-order bit is
// whether the piece is White (true means white), and the highest-order
// bit is meaningless.
typedef uint64_t Piece;


// The Board itself.
struct boardRec;
typedef struct boardRec *Board;


// Allocate and return a new Board, in the standard starting position. Returns
// NULL on failure, the starting Board on success.
Board AllocateBoard();


// Free a Board.
//
// Arguments:
//
//  - board. The board to be freed.
void FreeBoard(Board board);


// Get the piece at the given position. a1 -> 1, a2 -> 2, ..., c3 -> 19,
// ..., h8 -> 64. 
//
// Parameters:
//
//  - board. The board we're looking at.
//  - position. The position we want to examine. a1 -> 1, ..., c3 -> 19, ...,
//    h8 -> 64.
//
// Returns a Piece on success, 0 on failure.
Piece GetPiece(Board board, int position);


// Check whether a move is legal, i.e. whether the piece at the first
// argument (a position) can be moved to the second argument (a position).
//
// Arguments:
//
//  - board. The board we're querying.
//  - from. The square we're trying to move from. Should be an int 1-64.
//  - to. The square we're moving to. Should be an int 1-64.
//
// Returns true if the move is possible, false otherwise (no piece at "from",
// either position is invalid, etc).
bool IsLegal(Board board, int from, int to);


// Set the Piece to which promoted pawns should change. Defaults to queen, so
// you only need to call this if you plan on promoting a pawn to something
// other than a queen (or want a queen but just did a different promotion).
//
// Arguments:
//
//  - board. The board to set piece promotion on.
//  - piece. The piece that pawns should be promoted to.
void SetPromoPiece(Board board, Piece piece);


// Move a piece from one position to another.
//
// Arguments:
//
//  - board. The board we're moving on.
//  - from. the square we're trying to move from. Should be an int 1-64.
//  - to. The square we're moving to. Should be an int 1-64.
//
// This function does no logic checking, so it's
// a good idea to use IsLegal() before you call it. Won't work if either of the
// position arguments doesn't make sense.  If the move is a pawn promotion, the
// pawn will change into the Piece last passed to SetPromoPiece() defaulting
// to a queen.
void MakeMove(Board board, int from, int to);


// Get an array of pieces representing the board. The element at the first
// index will be the piece at a1 (or empty), the second element will be the
// piece at a2, and so on until the 64th element will be the piece at h8.
//
// Arguments:
//
//  - board. The board we're getting the array representation of.
//
// Returns the array representation of the passed board.
Piece[] GetArrayRepresentation(Board board);


/* There should be bitboard support here, too. All in good time... */


// Print the board. Empty squares will be represented by "."
//
// Arguments:
//
//  - board. The board to print.
void PrintBoard(Board board);


#endif // _BEGGERS_BOARD_
