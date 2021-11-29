count = int(input())

for i in range(count):
    omr = input()
    omr2 = list(omr)
    sum = 0
    c = 1

    for j in omr2:
        if j == 'O':
            sum += c
            c += 1
        else:
            c = 1

    print(sum)
