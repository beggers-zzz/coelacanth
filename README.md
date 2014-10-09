coelacanth
=====

Coelacanth is the raddest, baddest (and currently-incomplete-est) chess engine I've ever written in the C programming language (read: the only chess engine I've ever written in C (or at all, for that matter)).

Building
--------

To build coelacanth, first get the code and run `scripts/setup` from the root directory. Then, simply `make`. This builds the executable and the test suite (neither one is complete yet). Alternatively, type `make coelacanth` to build just the executable, or `make test` to build just the tests.

Developed/tested on an Intel(R) Core(TM) i7-3537U CPU @ 2.00GHz running 64-bit Arch Linux.

Testing
-------

Once you've built the tests, `./test` will execute the test suite. If you get any weird errors, drop me a line (email below).

Playing
-------

Once you've built the executable and all the tests are passing, just run `./coelacanth`. Move input is of the form "e2e4", NOT algebraic notation.

Issues
------

This is the first real-sized project that I'm doing on my own, and it's been quite a while since I worked in C. Comments and constructive criticism are appreciated! If something seems amiss, open an issue or drop me a line at <ben.eggers36@gmail.com>.
