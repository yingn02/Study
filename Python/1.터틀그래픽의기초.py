import turtle
t = turtle.Turtle()

s = turtle.Screen()
s.title("heart")
s.bgcolor("gray")

t.begin_fill()

t.width(3)
t.color("black")
t.fillcolor("limegreen")

t.left(45)
t.forward(195)
t.circle(80,225)

t.left(180)
t.circle(80,225)
t.forward(195)

t.end_fill()

