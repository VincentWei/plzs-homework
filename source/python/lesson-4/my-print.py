#!/usr/bin/python3

import sys
import io

def my_print(*objects, sep=' ', end='\n', file=None, flush=False):

    if file is None:
        file = sys.stdout

    for x in objects:
        s = str(x)
        for c in s:
            file.write(c)
        file.write(sep)

    file.write(end)
    if flush:
        file.flush()

my_print('This is an integer:', 3)

