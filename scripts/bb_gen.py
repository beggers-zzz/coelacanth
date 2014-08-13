#!/bin/python2
# Author: Ben Eggers <ben.eggers36@gmail.com>
# License: MIT
#
# This script generates bitboards (12, to represent the board entirely) from
# input the user passes in interactively. It prints out hex, or saves the
# results to a file if one is passed in.

import fileinput
import sys


pieces = ['p', 'n', 'b', 'r', 'q', 'k', 'P', 'N', 'B', 'R', 'Q', 'K']

def main():
    """
    Reads 8 lines at a time from the file named by the first argument,
    converting them into a board and getting all the bitboards for them.
    Then prints them out to a file named by the second command-line argument.
    """
    fname = sys.argv[1]
    fin = open(fname, 'r')

    fname = sys.argv[2]
    fout = open(fname, 'w')

    current = []  # the board we're reading

    for line in fin.read().splitlines():
        check_formatting(line)
        current.append(line)

        if len(current) == 8:
            # we have a full board
            process_board(current, fout)
            current = []


def check_formatting(line):
    """
    Make sure the passed line is formatted properly--every other character
    should be a space, and the rest should either be p, n, b, r, q, k, ., or
    any of those but capitalized.
    """
    assert len(line) == 15
    for i, c in enumerate(line):
        if i % 2 == 1:
            assert c == ' '
        else:
            assert c == "." or c in pieces


def process_board(board, file):
    """
    Takes a board and gets the hex strings for the bitboards, then prints them
    to the passed file.
    """
    dotmaps = dot_maps_from_board(board)
    for map in dotmaps:
         file.write("%s: %s\n" % (map['name'], dot_map_to_hex(map['map'])))
    file.write("\n")


def dot_maps_from_board(board):
    """
    Takes in a board and returns a map of "bPawn"(or whatever): DOT_MAP, where
    each dot map represents the "bit map" for that piece.
    """
    maps = []

    for piece in pieces:
        map = {}
        map['name'] = piece
        map['map'] = _make_map(board, piece)
        maps.append(map)

    return maps


def dot_map_to_hex(dot_map):
    """
    Takes a dot map and returns a the hex representing it as a bitboard. The
    hex returned is a string (not the actual hex bitboard) so it can easily
    be put into programs.
    """
    return "0x%s" % ("%x" % int("".join(dot_map), 2)).zfill(16)
    # I have formatted your strings. Pray I do not format them further.


def _make_map(board, piece):
    lines = []

    for line in board:
        new_line = ""
        for c in line:
            if c == piece:
                new_line += '1'
            elif c == ' ':
                new_line += ''
            else:
                new_line += '0'

        lines.append(new_line[::-1])
    return lines

if __name__ == "__main__":
    main()
