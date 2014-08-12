CC = gcc

CFLAGS = -g -Wall -Wpedantic -std=gnu99 -O5

HEADERS = Board.h Board_priv.h
OBJS = Board.o

all: Board.o FORCE

%.o: %.c $(HEADERS) FORCE
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	/bin/rm -f *.o *.gch

FORCE:
