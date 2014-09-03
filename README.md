coelacanth
=====

Trying to write a chess engine.


Building
--------

To build coelacanth, first get the code and run `scripts/setup` from the root directory. Then, simply `make`. This builds the executable and the test suite (neither one is complete yet). Alternatively, type `make coelacanth` to build just the executable, or `make test` to build just the tests.

Developed/tested on an Intel(R) Core(TM) i7-3537U CPU @ 2.00GHz running 64-bit Arch Linux.

Playing
-------

Once you've built the executable and all the tests are passing, just run `./coelacanth`. Move input is of the form "e2e4", NOT algebraic notation.

Issues
------

This is the first real-sized project that I'm doing on my own, and I also don't have much experience with C. Comments and constructive criticism are appreciated! If something seems amiss, open an issue or drop me a line at <ben.eggers36@gmail.com>.
