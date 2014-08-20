/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the MoveStack.

*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>  // for memcpy

#include "MoveStack.h"

typedef struct stackRec {
    int          current;
    stackNode    nodeArray[1000];
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

    ns = AllocateStack();
    if (ns == NULL) {
        return ns;
    }

    ns->current = s->current;
    memcpy(&ns->nodeArray, &s->nodeArray, sizeof(ns->nodeArray));

    return ns;
}

void PushStack(MoveStack s, stackNode n) {
    s->nodeArray[(s->current)++] = n;
}

stackNode *PopStack(MoveStack s) {
    return s->nodeArray + --(s->current);
}

stackNode *PeekStack(MoveStack s) {
    return s->nodeArray + s->current - 1;
}
