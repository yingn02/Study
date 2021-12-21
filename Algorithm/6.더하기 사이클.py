num = int(input())
check = num
new_num = 0
temp = 0
count = 0
while True:
    temp = num//10 + num%10 # 2 + 6
    new_num = (num%10)*10 + temp%10 # 6 + 8
    count += 1
    num = new_num # 14
    if new_num == check:
        break
print(count)