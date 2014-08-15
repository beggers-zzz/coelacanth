CC = gcc
CFLAGS = -g -Wall -std=gnu99 -Wpedantic -O0

AR = ar
ARFLAGS = rcs

HEADERS = util_tests.h
OBJS = MoveStack_test.o ../../util/MoveStack.o


all: libutiltest.a

libutiltest.a: $(OBJS) $(HEADERS)
	$(AR) $(ARFLAGS) libutiltest.a $(OBJS)

%o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<	

clean: FORCE
	/bin/rm -f libutiltest.a *.o *.gch

FORCE:
