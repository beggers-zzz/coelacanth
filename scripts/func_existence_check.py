#!/bin/python2
# Author: Ben Eggers <ben.eggers36@gmail.com>
# License: MIT
#
# Recursively reads all files in the passed directory (defaults to coelacanth).
# Finds all function declarations in .h files, and makes sure there is a
# corresponding function definition in a .c file. Only checks that there is
# a definition for each declaration, not that they are in sensible locations
# with respect to one another, or anything other advanced stuff.

import os

DEFAULT_DIR = "."

def main():
    print os.getcwd()
    os.exit(1)
