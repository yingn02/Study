t = int(input())

for i in range(t):
    h, w, n = map(int, input().split())
    y = 0
    x = 1
    for j in range(n):
        if y < h:
            y += 1
        else:
            y = 1
            x += 1

    if x < 10:
        y = str(y)
        x = str(x)
        print(y+"0"+x)
    else:
        y = str(y)
        x = str(x)
        print(y+x)