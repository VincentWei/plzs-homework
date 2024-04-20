#!/usr/bin/python3.10

# this is my first Python function
def area_of_square(d):
    return d ** 2

# this is my second Python function
def area_of_triangle(d, h):
    return d * h / 2

s = area_of_square(10) + area_of_triangle(10, 10)
print(s)

quit()

