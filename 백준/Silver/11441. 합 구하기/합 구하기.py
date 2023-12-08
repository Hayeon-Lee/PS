import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

m = int(input())
answer = []

for i in range(m):
    start, end = map(int, input().split())
    section = arr[start-1:end]
    print(sum(section))
