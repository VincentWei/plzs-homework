#!/usr/bin/python3

import sys
import io

def my_print(*args, sep=' ', end='\n', file=None, flush=False):

    if file is None:
        file = sys.stdout

    contents = sep.join(map(str, args)) + end
    file.write(contents)
    file.write(end)
    if flush:
        file.flush()

my_print('This is an integer:', 3)

