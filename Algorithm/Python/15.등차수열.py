n = int(input())
g = 99

if n < 100:
    print(n)
else:
    for x in range(100,n+1):
        x = str(x)
        a = int(x[0]) - int(x[1])
        b = int(x[1]) - int(x[2])
        if a == b:
            g = g + 1
        else:
            g = g
    print(g)