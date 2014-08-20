/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the MoveStack.

*/

#include <stdbool.h>
#include <stdlib.h>

#include "MoveStack.h"

typedef struct stackRec {
    int          nodeCount;
    stackNode    nodeArray[1000];
} stackRec;


MoveStack AllocateStack() {
    MoveStack s = (MoveStack) malloc(sizeof(stackRec));
    s->nodeCount = 0;
    return s;
}

void FreeStack(MoveStack s) {
    free(s);
}

int StackSize(MoveStack s) {
    return s->nodeCount;
}

MoveStack StackCopy(MoveStack s) {
    MoveStack ns;

    ns = AllocateStack();
    if (ns == NULL) {
        return ns;
    }

    memcpy(ns, s, sizeof(stackRec));

    return ns;
}

void PushStack(MoveStack s, stackNode n) {
    s->nodeArray[(s->nodeCount)++] = n;
}

stackNode *PopStack(MoveStack s) {
    return s->nodeArray + --(s->nodeCount);
}

stackNode *PeekStack(MoveStack s) {
    return s->nodeArray + s->nodeCount - 1;
}
