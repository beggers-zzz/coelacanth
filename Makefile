CC = gcc
CFLAGS = -g -Wall -W -Wextra -Wimplicit-function-declaration -Wpedantic \
-std=gnu99 -O3
LDFLAGS = -flto -O3

EXENAME := coelacanth
TESTEXENAME := run_tests

DIRS := core static util
TEST_DIR := test
OBJ_DIR := obj
BIN_DIR := bin

INCLUDES := $(DIRS:%=-I%)
TEST_INCLUDES := -I$(TEST_DIR) $(DIRS:%=-Itest/%)

SRCS = $(wildcard **/*.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADERS = $(wildcard **/*.h)

TEST_SRCS = $(wildcard $(TEST_DIR)/**/*.c)
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)
TEST_HEADERS = $(wildcard $(TEST_DIR)/**/*.h)


all: setup coelacanth test

setup: FORCE
	scripts/setup

coelacanth: $(OBJ_DIR)/Coelacanth.o $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(EXENAME) $(OBJ_DIR)/Coelacanth.o \
 $(OBJS) $(LDFLAGS)

test: $(OBJ_DIR)/Tests.o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TESTEXENAME) $(OBJ_DIR)/Tests.o $(OBJS) \
 $(TEST_OBJS) -lcheck $(LDFLAGS)

# NOTE: We're opting for slightly more time spent compiling than is necessary
# because every .o depends on every .h. This allows for a much simpler
# Makefile. Compile times are still <1s as of this writing, but if they start
# taking prohibitively long this system may have to change.

$(OBJ_DIR)/Tests.o: Tests.c $(HEADERS) $(TEST_HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean: FORCE
	/bin/rm -rf $(BIN_DIR) $(OBJ_DIR)

FORCE:
