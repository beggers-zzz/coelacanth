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

typedef struct MoveStackNode {
    int         fromSquare;
    int         toSquare;
    char        takenPiece;
    int         prevQuietCounter;
    int         prevEnPassant;
    bool        wCastle;
    bool        bCastle;
} MoveStackNode;

struct stackRec;
typedef struct stackRec *MoveStack;

// Get a new, empty stack.
MoveStack AllocateStack();

// Free a stack
void FreeStack(MoveStack s);

// Copy a stack
MoveStack StackCopy(MoveStack s);

bool StackEQ(MoveStack s1, MoveStack s2);

// Stack stuff

int StackSize(MoveStack s);

void PushStack(MoveStack s, MoveStackNode n);

// Caller is *NOT* responsible for this memory--DO NOT FREE
MoveStackNode *PopStack(MoveStack s);
MoveStackNode *PeekStack(MoveStack s);


bool sneq(MoveStackNode sn1, MoveStackNode sn2);

#endif // _COELACANTH_MOVE_STACK_
