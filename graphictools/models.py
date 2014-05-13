from math import *
import copy

class Point:

    def __init__(self,x,y):
        self.x = x
        self.y = y

    def rotate_deg(self, deg, origin):
        angle = radians(deg)
        new_x = (self.x-origin.x) * cos(angle) - (self.y - origin.y) * sin(angle);
        new_y = (self.x-origin.x) * sin(angle) + (self.y - origin.y) * cos(angle);
        self.x = new_x + origin.x
        self.y = new_y + origin.y

    def move(self, x, y):
        self.x += x
        self.y += yA

    def __add__(self, other):
        self.x += other.x
        self.y += other.y

    def __sub__(self, other):
        p = Point(self.x, self.y)
        p.x -= other.x
        p.y -= other.y
        return p

    def __str__(self):
        return "("+str(self.x)+","+str(self.y)+")"


class Line:

    def __init__(self,a,b):
        self.a = copy.copy(a)
        self.b = copy.copy(b)

    def rotate_deg(self, angle, origin):
        self.a.rotate_deg(angle, origin)
        self.b.rotate_deg(angle, origin)

    def draw(self, w, fill="red"):
        """
        use tkinter function create_line to draw on the given window object
        """
        w.create_line(self.a.x, self.a.y, self.b.x, self.b.y, fill=fill)

    def center(self):
        return Point( (self.a.x + self.b.x) / 2, (self.a.y + self.b.y) / 2 )

class Triangle:

    def __init__(self,a,b,c):
        self.a = copy.copy(a)
        self.b = copy.copy(b)
        self.c = copy.copy(c)

    def draw(self, w, fill="blue"):
        w.create_line(self.a.x, self.a.y, self.b.x, self.b.y, fill=fill)
        w.create_line(self.b.x, self.b.y, self.c.x, self.c.y, fill=fill)
        w.create_line(self.c.x, self.c.y, self.a.x, self.a.y, fill=fill)

