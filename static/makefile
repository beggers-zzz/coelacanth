CC = gcc
AR = ar

ARFLAGS = rcs
CFLAGS = -g -Wall -std=gnu99 -Wpedantic -O5

HEADERS = globals.h init_board.h
OBJS = init_board.o

libglobals.a: $(OBJS) $(HEADERS) FORCE
	$(AR) $(ARFLAGS) libglobals.a $(OBJS)

%.o: %.c $(HEADERS) FORCE
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	/bin/rm -f *.o *.gch libglobals.a

FORCE:
