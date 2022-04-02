#필요한 변수 선언
price, money, change = 0, 0, 0
c1000s, c500s, c100s = 0, 0, 0

#돈과 음료수 가격 입력
money = int(input("지불한 돈을 입력: "))
price = int(input("구입할 음료수 가격 입력: "))

#거스름돈 계산
change = money - price

#잔돈 계산
c1000s = change // 1000
change %= 1000
c500s = change // 500
change %= 500
c100s = change // 100
change %= 100
c50s = change // 50
change %= 50
c10s = change // 10
change %= 10

print("거스름돈은 %d원 입니다" %(money-price))
print("1000원 지폐의 수 => ", c1000s)
print("500원 동전의 수 => ", c500s)
print("100원 동전의 수 => ", c100s)
print("50원 동전의 수 => ", c50s)
print("10원 동전의 수 => ", c10s)
