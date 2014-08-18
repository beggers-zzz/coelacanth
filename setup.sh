# Author: Ben Eggers <ben.eggers36@gmail.com>
# License: MIT
#
# Sets up necessary directories for the coelacanth project.

OBJDIR=obj

for DIR in $(find . -type d -regex '^./[^.].*'); do
    mkdir -p obj/$DIR
done;
