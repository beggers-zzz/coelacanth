CC = gcc
CFLAGS = -g -Wall -std=gnu99 -Wpedantic -O5

OBJS = Board.o libglobals.a

DIRS = static test util


all: coelacanth test

coelacanth: Coelacanth.o $(OBJS)
	$(CC) $(CFLAGS) -o coelacanth Board.o Coelacanth.o $(LDFLAGS)

test: $(OBJS)
	$(MAKE) -C test
	mv test/test ./run_tests

Coelacanth.o: Coelacanth.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

libglobals.a:
	$(MAKE) -C static

clean: FORCE
	/bin/rm -f coelacanth run_tests *.o *.gch
	for d in $(DIRS); do (cd $$d && $(MAKE) clean ); done

FORCE:
