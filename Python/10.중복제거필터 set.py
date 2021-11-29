arr = []
for i in range(10):
    n = int(input())
    arr.append(n % 42)
arr = set(arr) #중복 제거 필터, 중복되는 것을 모두 삭제합니다.
print(len(arr)) #서로다른 것들의 개수를 셉니다.