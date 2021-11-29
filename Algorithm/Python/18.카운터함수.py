import collections

word = input().upper()
word = list(word)
c = collections.Counter(word) #리스트에서 요소의 개수를 딕셔너리형태로 반환함
c_max = []

for i, j in c.items(): # c.keys() 와 c.values()를 모두 포함함
    if j == max(c.values()):
        c_max.append(i)
        if len(c_max) > 1:
            print('?')
            break
if len(c_max) == 1:
    print(c_max[0])