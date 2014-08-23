/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Does main-y stuff.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Board.h"

// Parses the passed string and gets a move from it.
bool parseMove(char *in, int *from, int *to);

int main() {
    Board b;
    char input[10];
    int to, from;
    bool success;

    b = AllocateBoard();
    
    while (1) {
        PrintBoard(b);
        printf("\nNext move?:\n");
        fgets(input, 10, stdin);
        parseMove(input, &from, &to);
        success = MakeMove(b, from, to);
        if (!success) {
            printf("Invalid move, you fool.\n");
        }
    }

    FreeBoard(b);
}

bool parseMove(char *in, int *from, int *to) {
    *from = in[0] - 'a' + 8 * (in[1] - '1');
    *to = in[3] - 'a' + 8 * (in[4] - '1');
    return true;
}
