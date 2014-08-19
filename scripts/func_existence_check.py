#!/usr/bin/python2
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
IGNORE_DIRS = ["obj", "scripts"]


def main(root_dir):
    print "Beginning function check..."
    for dir, subdirs, files in os.walk(root_dir):
        print "Found dir %s" % dir
        
        # Get rid of subdirs we don't care about
        filter_dirs(subdirs)

        # And files that aren't .c or .h
        filter_files(files)

        for file in files:
            print "Found file %s" % file


def filter_dirs(dirs):
    for index, dir in enumerate(dirs):
        bname = dir.split('/')[-1]
        if bname in IGNORE_DIRS or bname[0] == '.':
            del dirs[index]


def filter_files(files):
    pass


if __name__ == "__main__":
    dir = DEFAULT_DIR
    main(dir)
