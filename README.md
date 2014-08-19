coelacanth
=====

Trying to write a chess engine.


Building
--------

To build coelacanth, first get the code and run `scripts/setup` from the root directory.

Then, simply `make`. This builds the executable and the test suite (neither one is complete yet).

Alternatively, type `make coelacanth` to build just the executable, or `make test` to build just the tests.


Layout
------

Here's the (tentative) layout:
  - `Coelacanth.c` Main function.
  - `Tests.c`: Runner for the test suites.
  - `core/`: Core functionality (board representation, move searching/deciding).
  - `scripts/`: Helpful scripts that aren't part of the finished program (e.g. bitboard generation).
  - `static/`: Global constants, such as the initial board configuration, pre-computed bitboards of what pieces can attack from where, etc. This may be refactored out.
  - `test/`: Tests.
  - `util/`: General data structures such as hash tables, etc to be used by multiple things in the program. This also may be refactored out.

Issues
------

This is my first real-sized project that I'm doing on my own, and I also don't have much experience with C. Comments and constructive criticism are appreciated! If something seems amiss, open an issue or drop me a line at <ben.eggers36@gmail.com>.
