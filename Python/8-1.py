'''
def sayHello(person, age=20):
    print("Hi", person, "나이는",age)
    print("안녕!")

sayHello(age=21,person="현명")
sayHello("진리")
sayHello("지혜",19)
sayHello("다은")



def sayHello(person, age):
    print("Hi", person, "나이는",age)

sayHello(age=21,person="현명")

sayHello("다은",20)

'''

def conInch(inch):
    cmV = inch * 2.54
    return cmV

print(conInch(3))

cmVal = conInch(3)
print(cmVal)

print(conInch(5))
