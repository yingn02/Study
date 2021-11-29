import sys

T = sys.stdin.readline().rstrip()
T = int(T)

while T > 0:
    T = T - 1
    A, B = map(int, sys.stdin.readline().split())
    print(A + B)
