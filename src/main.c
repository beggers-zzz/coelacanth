/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Does main-y stuff.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../util/Board.h"

// Parses the passed string and gets a move from it.
bool parseMove(char *in, Position *from, Position *to);


int main(int argc, char **argv) {
    Board b;
    char input[10];
    Position to, from;
    bool validIn;

    b = AllocateBoard();
    
    while (1) {
        PrintBoard(b);
        printf("\nNext move?:\n");
        fgets(input, 10, stdin);
        validIn = parseMove(input, &from, &to);
        if (validIn) {
            MakeMove(b, from, to);
        } else {
            printf("Invalid move, you fool.\n");
        }
    }

    FreeBoard(b);
}

bool parseMove(char *in, Position *from, Position *to) {
    from->col = in[0];
    from->row = in[1] - '0';
    to->col = in[3];
    to->row = in[4] - '0';
    return true;
}
