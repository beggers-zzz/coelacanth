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
    stackNode    nodeArray[STACK_SIZE];
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

void PushStack(MoveStack s, stackNode n) {
    s->nodeArray[(s->current)++] = n;
}

stackNode *PopStack(MoveStack s) {
    return s->nodeArray + --(s->current);
}

stackNode *PeekStack(MoveStack s) {
    return s->nodeArray + s->current - 1;
}
