self_num = set(range(1, 10001)) # set은 집합생성, 리스트와는 다른듯 하다
generated_num = set()

for i in range(1, 10001):
    for j in str(i): # i = 850 이라고하면, 8일때 5일 때 0일때를 range처럼 이용
        i = i + int(j)
    generated_num.add(i) #리스트는 append, 집합은 add

self_num = self_num - generated_num #전체에서 셀프넘버가 아닌걸 뺐다

for i in sorted(self_num): #정렬
    print(i)