N = int(input())
word = []
num = 0

for i in range(N):
    word.append(input().lower())

for i in word: #단어를 알파벳의 리스트로 만들고 알파벳이 반복되는지 확인
    if list(i) == sorted(i, key = i.find): # 1234 = 1342, 12344 != 41243
        num = num + 1

print(num)