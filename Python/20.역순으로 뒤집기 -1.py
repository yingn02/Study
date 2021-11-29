q1, q2 = map(str, input().split())

q1 = q1[::-1] # [::-1] 은 역순으로 바꿔줍니다
q2 = q2[::-1]

if q1 > q2:
    print(q1)
else:
    print(q2)