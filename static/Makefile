CC = gcc
AR = ar

ARFLAGS = rcs
CFLAGS = -g -Wall -std=gnu99 -Wpedantic -O5

HEADERS = globals.h init_board.h bitboard.h
OBJS = init_board.o

all: libglobals.a

libglobals.a: $(OBJS) $(HEADERS) 
	$(AR) $(ARFLAGS) libglobals.a $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	/bin/rm -f *.o *.gch libglobals.a

FORCE:
