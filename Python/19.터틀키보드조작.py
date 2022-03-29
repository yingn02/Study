import turtle
t = turtle.Turtle()
scr = turtle.Screen()

t.shape("turtle")
t.pensize(3)

def s_draw(x,y):
    t.goto(x,y)

def turnleft():
    t.left(15)

def turnright():
    t.right(15)

scr.onscreenclick(s_draw)
scr.onkey(t.penup,"Up")
scr.onkey(t.pendown,"Down")
scr.onkey(turnleft,"Left")
scr.onkey(turnright,"Right")
scr.onkey(t.clear,"Delete")
scr.listen()
scr.mainloop
