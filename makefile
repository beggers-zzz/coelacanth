CC = gcc

CFLAGS += -g -Wall -std=gnu99 -Wpedantic -O5

all: coelacanth

coelacanth: Board.o board/Board.h
	$(CC) $(CFLAGS) -o coelacanth board/Board.o core/coelacanth.c

Board.o: board/Board.c board/Board.h board/Board_priv.h
	$(CC) $(CFLAGS) -c -o board/Board.o board/Board.c

clean: FORCE
	/bin/rm -f board/Board.o board/Board.h.gch board/Board_priv.h.gch coelacanth

FORCE:
