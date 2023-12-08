import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
d = deque()

for index, value in enumerate(arr):
    d.append((value, index+1))

answer = []

while(True):
    next, index = d.popleft()
    answer.append(index)
    
    if (d):
        if next >= 0:
            for i in range(next-1):
                item = d.popleft()
                d.append(item)

        else:
            for i in range((next*-1)):
                item = d.pop()
                d.appendleft(item)

    else:
        break

for a in answer:
    print(a, end=' ')