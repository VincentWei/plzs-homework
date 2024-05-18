#!/usr/bin/python3

import sys

# n! = n * (n - 1)!
# n = 1, n! = 1
def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n - 1)

n = 0
while n <= 0:
    try:
        n = int(input("Please input a positive integer:"))
    except ValueError:
        n = 0

print("The current recursion limit:", sys.getrecursionlimit())
sys.setrecursionlimit(10000)
sys.set_int_max_str_digits(100000)

print(f"The factorial of {n} is:", factorial(n))

