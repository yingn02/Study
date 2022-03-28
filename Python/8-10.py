import turtle
t = turtle.Turtle()
scr = turtle.Screen()

def star(length):
    for n in range(5):
        t.fd(length)
        t.left(144)

def s_draw(x,y):
    turtle.bgcolor("black")
    t.up()
    t.goto(x,y)
    
    t.down()
    t.color("yellow")
    t.begin_fill()
    star(50) #위에있는거
    t.end_fill()

scr.onscreenclick(s_draw)
