CC = gcc

CFLAGS = -g -Wall -std=gnu99 -Wpedantic -O5

HEADERS = MoveStack.h


all: MoveStack.o

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	/bin/rm -f *.o *.gch

FORCE:
