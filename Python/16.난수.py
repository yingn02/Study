'''
import random

n = random.randint(1,6)

if n % 2 == 0 :
    print(n,"은 짝수")

else:
    print(str(n)+"은 홀수")

'''

n = int(input("숫자를 입력=>"))

if n % 3 == 0:
    print("3의 배수가 맞다")

else:
    print("3의 배수가 아니다")
