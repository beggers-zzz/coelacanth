/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

Does main-y stuff.

*/


#include <stdio.h>
#include <stdlib.h>

#include "../util/Board.h"

int main(int argc, char **argv) {
    Board b;
    char input[10];

    b = AllocateBoard();

    PrintBoard(b);
}
