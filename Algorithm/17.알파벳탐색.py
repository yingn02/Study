s = list(map(str, input())) #단어 입력
al = list("abcdefghijklmnopqrstuvwxyz") #알파벳 모음

ar = [-1 for i in range(len(al))] #알파벳 개수만큼 -1로 채웁니다

for i in range(len(s)):
    if ar[al.index(s[i])] == -1: #beakjoon의 알파벳을 탐색
        ar[al.index(s[i])] = i

for j in ar:
    print(j, end=" ")
