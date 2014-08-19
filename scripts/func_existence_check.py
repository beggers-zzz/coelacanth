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

    sources, headers = get_files(root_dir)

    for f in sources:
        print f

    for f in headers:
        print f


def get_files(root_dir):

    sources = []
    headers = []

    for dir, subdirs, files in os.walk(root_dir, topdown=True):

        filter_dirs(subdirs)

        for fn in files:
            fn = dir + '/' + fn
            if fn.endswith('.c'):
                sources.append(fn)
            elif fn.endswith('.h'):
                headers.append(fn)

    return sources, headers


def filter_dirs(dirs):
    for index, dir in enumerate(dirs):
        bname = dir.split('/')[-1]
        if bname in IGNORE_DIRS or bname.startswith('.'):
            del dirs[index]


if __name__ == "__main__":
    dir = DEFAULT_DIR
    main(dir)
