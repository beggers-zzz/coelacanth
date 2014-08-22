CC = gcc
CFLAGS = -g -Wall -W -Wextra -Wimplicit-function-declaration -Wpedantic -std=gnu11 -O3
LDFLAGS = -flto -O3

DIRS := core static util
TEST_DIR := tests
OBJ_DIR := obj

INCLUDES := $(DIRS:%=-I%)
TEST_INCLUDES := -I$(TEST_DIR) $(DIRS:%=-I$(TEST_DIR)/%)

SRCS = $(wildcard **/*.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADERS = $(wildcard **/*.h)

TEST_SRCS = $(wildcard $(TEST_DIR)/**/*.c)
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)
TEST_HEADERS = $(wildcard $(TEST_DIR)/**/*.h)


all: coelacanth test

coelacanth: $(OBJ_DIR)/Coelacanth.o $(OBJS)
	$(CC) $(CFLAGS) -o coelacanth $(OBJ_DIR)/Coelacanth.o $(OBJS) $(LDFLAGS)

test: $(OBJ_DIR)/Tests.o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o test $(OBJ_DIR)/Tests.o $(OBJS) $(TEST_OBJS) -lcheck $(LDFLAGS)

# NOTE: We're opting for slightly more time spent compiling than is necessary
# because every .o depends on every .h. This allows for a much simpler
# Makefile. Compile times are still <1s as of this writing, but if they start
# taking prohibitively long this system may have to change.

$(OBJ_DIR)/Tests.o: Tests.c $(HEADERS) $(TEST_HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean: FORCE
	/bin/rm -f coelacanth test $(OBJ_DIR)/*.o $(OBJS)

FORCE:

.PHONY: clean 
