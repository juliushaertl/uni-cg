from tkinter import *
from graphictools.models import *
from graphictools.layer import *
from math import *


class Snowflake:

    def __init__(self, container):
        self.container = container

    def draw(self, base, level):
        """ Recursive draw method
        Divides baseline into four parts
        the line will only be drawn, if the recursion ends """

        a = base.a
        b = base.b

        if level > 0:
            delta = base.b - base.a
            px = a.x + delta.x / 3
            py = a.y + delta.y / 3
            rx = a.x + 2 * delta.x / 3
            ry = a.y + 2 * delta.y / 3
            p = Point(px, py)
            r = Point(rx, ry)
            q = Point(rx, ry)
            q.rotate_deg(60,  p)
            self.draw(Line(a,p), level-1)
            self.draw(Line(p,q), level-1)
            self.draw(Line(q,r), level-1)
            self.draw(Line(r,b), level-1)
        else:
            self.container.window.create_line(a.x, a.y, b.x, b.y)

if __name__ == "__main__":

    window = Layer()

    # Define triangle for snowflake
    a = Line(Point(100,400), Point(500,400))
    b = Line(a.b, a.a)
    b.rotate_deg(60, a.b)
    c = Line(b.b, b.a)
    c.rotate_deg(60, b.b)

    # Draw snowflake
    snow = Snowflake(window)
    size = 3

    snow.draw(a,size)
    snow.draw(b,size)
    snow.draw(c,size)

    mainloop()
