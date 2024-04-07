import turtle
t = turtle.Turtle()
def drawpolygon(points, color, t):
    t.up()
    t.fillcolor(color)
    t.goto(points[0])
    t.down()
    t.begin_fill()
    for i in points:
        t.goto(i)
    t.goto(0)
    t.end_fill()
def getmid(p1, p2):
    return ((p1[0] + p2[0])/2, (p1[1] + p2[1])/2)
def sierpinski(points, degree, t):
    colormap = ["Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Purple"]
    drawpolygon(points, colormap[degree], t)
    if degree > 0:
        sierpinski((points[0], getmid(points[0], points[1]), getmid(points[0], points[2])), degree - 1, t)
        sierpinski((points[1], getmid(points[1], points[0]), getmid(points[1], points[2])), degree - 1, t)
        sierpinski((points[2], getmid(points[2], points[1]), getmid(points[0], points[2])), degree - 1, t)
s=turtle.Screen()
points = [(0,0), (420, 420), (840, 0)]
sierpinski(points, 7, t)