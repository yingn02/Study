import sys

list1 = []
list2 = []
n = int(input())
m1 = list(map(int, sys.stdin.readline().split()))
m2 = max(m1)

for i in range(n):
    list1.append(m1[i])

for j in range(n):
    new_n = int(m1[j])/m2*100
    list2.append(new_n)

total = sum(list2)/len(list2) #리스트를 모두 더한 것 / 리스트 안에 있는 게 몇 개?

print(total)