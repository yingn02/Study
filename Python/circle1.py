import turtle
t=turtle.Turtle()
t.shape("turtle")

t.fd(100)
t.right(90)
t.fd(100)

t.circle(50)
t.write("거북아 안녕")
t.color("blue")
t.fillcolor("yellow")

t.begin_fill()
t.circle(50,360,3)
t.end_fill()

t.up()
t.goto(0,-200)
t.down()
t.fillcolor("green")

t.begin_fill()
t.circle(50,360,4)
t.end_fill()
