t = int(input())
k = 1 # 순간이동거리
cnt = 1 # 이동 횟수
o = 0 # 우주선의 현위치

for i in range(t):
    x, y = map(int, input().split())
    d = y-x # 두 지점 사이의 거리
    while True:
        o += k  # 위치를 업데이트 합니다
        cnt += 1
        k += 1
        d2 = d - o
        if k >= d2: # 중간 지점을 지나쳐서 초과함
            cnt += 1
            break

    print(cnt)
    # 중도포기


