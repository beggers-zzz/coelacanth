CC = gcc

CFLAGS = -g -Wall -Wpedantic -std=gnu99 -O5

all: Coelacanth.o

%.o: %.c
	$(CC) $(CFLAGS) -c Coelacanth.c

clean: FORCE
	/bin/rm -f *.o *.gch

FORCE:
