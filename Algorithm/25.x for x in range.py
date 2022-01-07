t = int(input())

for i in range(t):
    k = int(input())
    n = int(input())
    m = 0

    k0 = [x for x in range(1, n+1)]  # 0층 리스트
    for j in range(k):  # 층 수 만큼 반복
        for d in range(1, n):  # 1 ~ n-1까지 (인덱스로 사용)
            k0[d] += k0[d-1]  # 층별 각 호실의 사람 수를 변경
    print(k0[-1])  # 가장 마지막 수 출력

'''
>>> mylist = [x*x for x in range(3)] #리스트에 0 1 2를 제곱해서 저장
>>> for i in mylist: # 리스트에 있는 거 순서대로 시행할거임
...    print(i) # 순서대로 출력
0
1
4
'''
#11번 라인
#◐○
#  ◑  표에서 ◐ + ◑ = ○ 관계를 이용하여 0층의 정보를 업데이트하여 층의 수가 올라감
