from tkinter import *

class Layer:

    """ TK helper class 
    this class is used to draw different elements that implement a draw method
    like Line() in graphictools/models.py
    """

    def __init__(self):
        self.master = Tk()
        self.window = Canvas(self.master, width=600, height=600)
        self.window.pack()

    def draw(self, item, fill="black"):
        item.draw(self.window, fill=fill)


