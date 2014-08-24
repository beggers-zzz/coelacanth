/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the MoveStack.

*/

#include <stdbool.h>
#include <stdlib.h>

#include "MoveStack.h"

#define STACK_SIZE 1000

typedef struct stackRec {
    int          current;
    MoveStackNode    nodeArray[STACK_SIZE];
} stackRec;


MoveStack AllocateStack() {
    MoveStack s = (MoveStack) malloc(sizeof(stackRec));
    s->current = 0;
    return s;
}

void FreeStack(MoveStack s) {
    free(s);
}

int StackSize(MoveStack s) {
    return s->current;
}

MoveStack StackCopy(MoveStack s) {
    MoveStack ns;
    int i;

    ns = AllocateStack();
    if (ns == NULL) {
        return ns;
    }

    i = 0;
    while (i < s->current) {
        ns->nodeArray[ns->current++] = s->nodeArray[i++];
    }

    return ns;
}

bool StackEQ(MoveStack s1, MoveStack s2) {
    int i;

    if (s1->current != s2->current) {
        return false;
    }

    i = 0;
    while (i < s1->current) {
        if (!sneq(s1->nodeArray[i], s2->nodeArray[i])) {
            return false;
        }
    }

    return true;
}

void PushStack(MoveStack s, MoveStackNode n) {
    s->nodeArray[(s->current)++] = n;
}

MoveStackNode *PopStack(MoveStack s) {
    return s->nodeArray + --(s->current);
}

MoveStackNode *PeekStack(MoveStack s) {
    return s->nodeArray + s->current - 1;
}

bool sneq(MoveStackNode s1, MoveStackNode s2) {
    return s1.fromSquare == s2.fromSquare &&
           s1.toSquare == s2.toSquare &&
           s1.takenPiece == s2.takenPiece &&
           s1.prevQuietCounter == s2.prevQuietCounter &&
           s1.prevEnPassant == s2.prevEnPassant;
}
 
