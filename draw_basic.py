from graphictools.models import *
from graphictools.layer import *

if __name__ == "__main__":

    window = Layer()

    p1 = Point(100,100)
    p2 = Point(200,200)

    line = Line(p1, p2)
    window.draw(line)

    line.rotate_deg(90, Point(200,200))
    window.draw(line, fill="red")

    line.rotate_deg(90, line.center())
    window.draw(line, fill="green")

    mainloop()
