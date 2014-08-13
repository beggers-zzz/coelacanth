CC = gcc

CFLAGS += -g -Wall -std=gnu99 -Wpedantic -O5
LDFLAGS = -Lstatic -lglobals

all: coelacanth

coelacanth: Board.o Coelacanth.o libglobals.a
	$(CC) $(CFLAGS) -o coelacanth Board.o Coelacanth.o $(LDFLAGS)

Coelacanth.o: Coelacanth.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

libglobals.a:
	$(MAKE) -C static

clean: FORCE
	/bin/rm -f coelacanth *.o *.gch
	cd static; $(MAKE) clean

FORCE:
