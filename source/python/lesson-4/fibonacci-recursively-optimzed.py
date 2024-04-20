#!/usr/bin/python3

fibs = [0, 1]
def nth_fibonacci(n):
    global fibs

    if n < len(fibs):
        return fibs[n]

    if n <= 1:
        fib = n
    else:
        fib = nth_fibonacci(n - 1) + nth_fibonacci(n - 2)

    # IndexError
    fibs += (fib, )
    return fib

mx = 0
while mx <= 0:
    try:
        mx = int(input('Please input a positive integer: '))
    except ValueError:
        mx = 0

print(f"The Fibonacci numbers less than {mx}:")

for i in range(mx):
    a = nth_fibonacci(i)
    b = nth_fibonacci(i + 1)
    if a >= mx or b >= mx:
        print(a, end = '.\n')
        break
    else:
        print(a, end = ', ')

