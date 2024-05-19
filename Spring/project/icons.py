import time
import turtle

############################ DRAWING SECTION ####################################################################
#########################################

s = turtle.Screen()
t = turtle.Turtle()
t.hideturtle()

def circle(point, color):
    t.pensize(3)
    t.penup()
    t.goto(point)
    t.pendown()
    t.fillcolor(color)
    t.begin_fill()
    t.circle(11)
    t.pensize(2)
    t.circle(8)
    t.pensize(1)
    t.circle(5)
    t.circle(3)
    t.circle(1)
    t.end_fill()

circle((0, 0), "white")