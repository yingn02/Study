import turtle
t = turtle.Turtle()

def square(length):
    for n in range(5):
        t.fd(length)
        t.left(90)
        
def s_draw(x,y):
    turtle.bgcolor("skyblue")
    t.up()
    t.goto(x,y)
    t.down()
    t.color("orange")
    t.begin_fill()
    square(50)
    t.end_fill()

scr = turtle.Screen()
scr.onscreenclick(s_draw)
    
