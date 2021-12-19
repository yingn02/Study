a, b = map(int, input().split()) #두 개 받기
list = input().split() #여러개 받기
t = []

for c in range(a):
    if int(list[c]) < b:
        t.append(int(list[c]))
    else:
        pass

y = len(t)

for u in range(y):
    print(str(t[u]), end=' ')