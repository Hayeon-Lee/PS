import sys
from collections import deque
input = sys.stdin.readline

A, B = map(int, input().split())
queue = deque([(A,1)])
flag = 0

while queue:
    now, cnt = queue.popleft()

    if now == B: 
        print(cnt)
        flag = 1
        break

    first = now * 2
    second = int(str(now)+'1')

    if first <= B: queue.append((first, cnt+1))
    if second <= B: queue.append((second, cnt+1))


if flag == 0:
    print(-1)