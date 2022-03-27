import random

n = random.randint(1,10)

print("숫자맞추기 게임, 1~10 숫자를 입력")

for i in range(5):
    guess = int(input("숫자입력->"))

    if guess == n:
        print("정답")
        break

    elif guess > n:
        print("정답보다 큽니다")

    else:
        print("정답보다 작습니다")


    if i == 4:
        print("탈락, 기회소진")
