#!/usr/bin/python3

class FibIterator(object):
    def __init__(self, a1, a2):
        self.a = a1
        self.b = a2

    def __next__(self):
        r = self.a
        self.a, self.b = self.b, self.a + self.b
        return r

class Fibonacci(object):
    def __init__(self, a1, a2):
        self.a1 = int(a1)
        self.a2 = int(a2)
        if self.a1 > self.a2 or self.a1 < 0 or self.a2 == 0:
            raise(ValueError)

    def make_list(self, maxn):
        l = []
        a, b = self.a1, self.a2
        while a <= maxn:
            l += (a, )
            if a == maxn or b > maxn:
                break
            a, b = b, a + b
        return l

    def __iter__(self):
        return FibIterator(self.a1, self.a2)

def check_fibs(a1, a2, maxn):
    fib = Fibonacci(a1, a2)

    fibs = fib.make_list(maxn)
    for i in range(len(fibs)):
        if i == 0:
            continue

        div = fibs[i-1] / fibs[i]
        print(f'{fibs[i-1]} / {fibs[i]}: {div}')

cases = (
    (2, 3, 10000),
    (0, 1, 10000),
    (50, 51, 10000),
    (999, 9999, 100000000),
)

for x in cases:
    check_fibs(*x)
