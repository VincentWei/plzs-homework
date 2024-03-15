#!/usr/bin/python3

# 计算正方形面积的函数
def area_of_square(a):
    return a ** 2

# 计算三角形面积的函数
def area_of_triangle(a, h):
    return a * h / 2

# the function to calculate area of a circle.
def area_of_circle(r):
    return 3.14159265 * r * r

a = int(input("Please input the length of the side of a square: "))
s = area_of_square(a)
# area_of_square(11): 121
print("area_of_square(", a, "): ", s)

a = int(input("Please input the length of one side of a triangle: "))
h = int(input("Please input the lengthe of the height on the side: "))
s = area_of_triangle(a, h)
# area_of_triangle(11, 10): 55
print("area_of_triangle(", a, ", ", h, "): ", s)

r = int(input("Please input the length of the radius of a circle: "))
s = area_of_circle(r)
# area_of_circle(0): 0
print("area_of_circle(", r, "): ", s)
