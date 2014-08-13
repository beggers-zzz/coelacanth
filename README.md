coelacanth
=====

Trying to write a chess engine.


Building
--------

To build coelacanth, just get the code and type `make`. This currently only builds the executable, because there are no tests. Also, the executable doesn't do anything interesting yet.


Layout
------

Here's the (tentative) layout:

  - `Board{.c, .h, _priv.h}` contain the Board model, and associated functions.
  - `Brain{.c, .h, _priv.h}` (TODO): contain the actual move-search logic.
  - `Coelacanth.c` contains the main function.
  - `static/`: contains global constants, such as the initial board configuration, pre-computed bitboards of what pieces can attack from where, etc. This may be refactored out.
  - `test/` (TODO): tests.
  - `ui/` (TODO): tentative, if I end up building a GUI.
  - `util/` (TODO): general, non-chess-specific data structures such as hash tables, etc. This also may be refactored out.

This is my first real-sized project that I'm doing on my own, and I also don't have much experience with C. Comments and constructive criticism are appreciated! The main two things I'm concerned about are (in this order) architecture and coding style, so if something seems amiss drop me a line at <ben.eggers36@gmail.com>.
