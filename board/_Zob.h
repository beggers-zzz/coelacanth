/*

Author: Ben Eggers <ben.eggers36@gmail.com>
License: MIT

This file contains hashing stuff. Don't include it unless you really know
what you're doing--just use the hash found in Board.h.

In defense of the choice to break this out into its own file: testing.

*/


#ifndef _COELACANTH_BOARD_ZOB_
#define _COELACANHT_BOARD_ZOB_

#include <stdint.h>

#include "Board.h"
#include "Board_priv.h"

void ZobristInit(Board b);

uint64_t ZobristEntireBoard(Board b);

#endif  // _COELACANTH_BOARD_ZOB_
