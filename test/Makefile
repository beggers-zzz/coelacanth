CC = gcc
CFLAGS = -Wall -std=gnu99 -Wpedantic -O0

HEADERS = util/util_tests.h

DIRS = util


all: test

test: $(HEADERS)
	for d in $(DIRS); do (cd $$d && $(MAKE) ); done
	$(CC) $(CFLAGS) -o test test_main.c -lcheck -L./util -lutiltest

clean: FORCE
	/bin/rm -f *.o *.gch test
	for d in $(DIRS); do (cd $$d && $(MAKE) clean ); done

FORCE:
