CC = gcc

CFLAGS = -g -Wall -Wpedantic -std=gnu99 -O2

all: main

main: Board.o Board.h
    $(CC) $(CFLAGS) -o main util/Board.o main.c
