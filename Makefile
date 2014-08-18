CC = gcc
CFLAGS = -g -Wall -W -Wextra -Wimplicit-function-declaration -Wpedantic \
        -std=gnu99 -O3
LDFLAGS = -flto -O3

EXENAME = coelacanth
TESTEXENAME = run_tests

DIRS := core static util
TESTDIR := test
OBJDIR := obj

INCLUDES := $(DIRS:%=-I%)
TESTINCLUDES := -I$(TESTDIR) $(DIRS:%=-Itest/%)

SRCS = $(wildcard **/*.c)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
HEADERS = $(wildcard **/*.h)

TESTSRCS = $(wildcard $(TESTDIR)/**/*.c)
TESTOBJS = $(TESTSRCS:%.c=$(OBJDIR)/%.o)
TESTHEADERS = $(wildcard $(TESTDIR)/**/*.h)


all: coelacanth test

coelacanth: $(OBJDIR)/Coelacanth.o $(OBJS)
	$(CC) $(CFLAGS) -o $(EXENAME) $(OBJDIR)/Coelacanth.o $(OBJS) $(LDFLAGS)

test: $(OBJDIR)/Tests.o $(OBJS) $(TESTOBJS)
	$(CC) $(CFLAGS) -o $(TESTEXENAME) $(OBJDIR)/Tests.o $(OBJS) $(TESTOBJS) \
    -lcheck $(LDFLAGS)

# NOTE: We're opting for slightly more time spent compiling than is necessary
# because every .o depends on every .h. This allows for a much simpler
# Makefile. Compile times are still <1s as of this writing, but if they start
# taking prohibitively long this system may have to change.

$(OBJDIR)/Tests.o: Tests.c $(HEADERS) $(TESTHEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(TESTINCLUDES) -c -o $@ $<

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean: FORCE
	/bin/rm -f $(EXENAME) $(TESTEXENAME) $(OBJS) $(TESTOBJS) $(OBJDIR)/*.o

FORCE:
