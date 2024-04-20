#!/usr/bin/python3

class Circle(object):
    pi = 3.14159265

    def __init__(self, r):
        self.r = float(r)
        if self.r < 0:
            raise(ValueError)

    def perimeter(self):
        return 2. * self.pi * self.r

    def area(self):
        return self.pi * self.r * self.r

    def __str__(self):
        return 'A circle with a radius of ' + str(self.r) + '.'

class Square(object):
    def __init__(self, d):
        self.d = float(d)
        if self.d < 0:
            raise(ValueError)

    def perimeter(self):
        return self.d * 4.0

    def area(self):
        return self.d * self.d

    def __str__(self):
        return 'A square with a side of ' + str(self.d) + '.'

class Rectangle(object):
    def __init__(self, d1, d2):
        self.d1 = float(d1)
        self.d2 = float(d2)
        if self.d1 < 0 or self.d2 < 0:
            raise(ValueError)

    def perimeter(self):
        return (self.d1 + self.d2) * 2

    def area(self):
        return self.d1 * self.d2

    def __str__(self):
        return 'A rectangle with sides of ' + str(self.d1) + ' and ' +  str(self.d2) + '.'

circle = Circle(5)
print(circle)

square = Square(5)
print(square)

rect = Rectangle(5, '5.0')
print(rect)
