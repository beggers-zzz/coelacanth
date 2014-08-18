/*

Author: Ben Eggers
License: MIT

Stack used in ../Board.c to implement UnmakeMove(). The name is pretty
self-descriptive...it's a stack of moves. What more do you want, huh?

The idea is that given a move stack *AND THE CURRENT BOARD*, one would
be able to repeatedly pop moves off the stack and apply their changes
to the board (putting pieces back, giving back castle rights, etc)
until the board is once again the starting board. At this point the
stack would be empty.

*/

#ifndef _COELACANTH_MOVE_STACK_
#define _COELACANTH_MOVE_STACK_

#include <stdbool.h>

typedef struct stackNode {
    int         fromSquare;
    int         toSquare;
    char        takenPiece;
    int         prevQuietCounter;
    int         prevEnPassant;
    bool        wCastle;
    bool        bCastle;
} stackNode;

struct stackRec;
typedef struct stackRec *MoveStack;

// Get a new, empty stack.
MoveStack AllocateStack();

// Free a stack
void FreeStack(MoveStack s);

// Stack stuff

int StackSize(MoveStack s);

void PushStack(MoveStack s, stackNode n);

// Caller is *NOT* responsible for this memory--DO NOT FREE
stackNode *PopStack(MoveStack s);
stackNode *PeekStack(MoveStack s);

#endif // _COELACANTH_MOVE_STACK
