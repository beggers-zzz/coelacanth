CC = gcc

CFLAGS += -g -Wall -std=gnu99 -Wpedantic -O2

all: main

main: Board.o util/Board.h
	$(CC) $(CFLAGS) -o main util/Board.o src/main.c

Board.o: util/Board.c util/Board.h util/Board_priv.h
	$(CC) $(CFLAGS) -c -o util/Board.o util/Board.c

clean: FORCE
	/bin/rm -f util/Board.o util/Board.h.gch util/Board_priv.h.gch main

FORCE:
