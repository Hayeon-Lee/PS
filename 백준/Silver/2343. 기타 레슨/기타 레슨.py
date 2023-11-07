import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
lectures = deque(list(map(int,input().split())))

start = max(lectures)
end = sum(lectures)
answer = 0

while start <= end:
    mid = (start + end) // 2

    total = 0
    count = 1

    for l in lectures:
        if total + l > mid:
            count += 1
            total = 0
        total += l
    
    if count <= M:
        answer = mid
        end = mid - 1

    else:
        start = mid + 1

print(answer)