c = int(input())

for i in range(c):
    who = 0
    case = list(map(int, input().split()))
    man = case[0]

    del case[0]
    p = sum(case) / man

    for j in range(man):
        if case[j] > p:
            who += 1
        else:
            pass
    per = who / man * 100

    print("%.3f"% per, end='') # "%.3f"% 를 맨앞에붙이면 소수점 나타내고 싶은만큼 가능
    print("%")