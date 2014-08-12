CC = gcc

CFLAGS += -g -Wall -std=gnu99 -Wpedantic -O5
LDFLAGS = -Lstatic -lglobals


DIRS = board static core



all: coelacanth

coelacanth: Board.o Coelacanth.o libglobals.a
	$(CC) $(CFLAGS) -o coelacanth board/Board.o core/Coelacanth.o $(LDFLAGS)

Board.o: 
	$(MAKE) -C board

Coelacanth.o:
	$(MAKE) -C core

libglobals.a:
	$(MAKE) -C static

clean: FORCE
	/bin/rm -f coelacanth
	for d in $(DIRS); do (cd $$d && $(MAKE) clean); done

FORCE:
