import turtle
t=turtle.Turtle()

t.shape("turtle")

r=int(turtle.textinput("반지름입력","반지름의 길이를 입력하세요"))


area = 3.14*r**2

t.circle(r)

t.up()

t.goto(0,0)
t.write("원의의 넓이->"+str(area))
