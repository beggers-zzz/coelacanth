/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Implementation of the MoveStack.

*/

#include <stdbool.h>

struct stackRec {
    int          nodeCount;
    stackNode    nodeArray[1000];
}


MoveStack AllocateStack() {
    MoveStack s = (MoveStack) malloc(sizeof(stackRec));
    s->nodeCount = 0;
}

void FreeStack(MoveStack s) {
    free(s);
}

void PushStack(MoveStack s, stackNode n) {
    s->nodeArray[nodeCount++] = n;
}

stackNode *PopStack(MoveStack s) {
    return s->nodeArray[--nodeCount];
}

stackNode *PeekStack(MoveStack s) {
    return s->nodeArray[nodeCount];
}