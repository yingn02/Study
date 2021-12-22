import sys

num1 = int(input())
num2 = list(map(int, sys.stdin.readline().split()))

print(min(num2), max(num2))