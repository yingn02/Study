import math

a, b, v = map(int, input().split())

day = math.ceil((v-a)/(a-b)) + 1 # (a-b)*n + a = v 그리고 math.ceil은 소수점을 반올림 (4.2일 = 5일)
print(day)