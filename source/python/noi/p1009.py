#!/usr/bin/python3

def factorial(n):
    r = n
    for x in range(1, n):
        r *= x

    return r

def factorial_recursive(n):
    if n == 0:
        return 1
    return n * factorial_recursive(n - 1)

assert(factorial(2) == 2)
assert(factorial(5) == 5 * 4 * 3 * 2)

assert(factorial_recursive(2) == 2)
assert(factorial_recursive(5) == 5 * 4 * 3 * 2)

maxn = int(input())
s = 0
for n in range(0, maxn):
    s += factorial_recursive(n + 1)

print(s)
