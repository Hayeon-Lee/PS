import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
queue = deque(list(i for i in range(1, N+1)))
target_queue = deque(list(map(int, input().split())))

answer = 0
head_index = 0
tail_index = N-1

while(target_queue):
    target = target_queue.popleft()
    target_index = 0
    
    if target == queue[0]:
        queue.popleft()
        tail_index = len(queue)-1
        continue
    
    for i in range(0, len(queue)):
        if queue[i] == target: target_index = i
    
    left = target_index - head_index
    right = tail_index - target_index

    if (left <= right):
        while(queue[0] != target):
            tmp = queue.popleft()
            queue.append(tmp)
            answer += 1
    else:
        while(queue[0] != target):
            tmp = queue.pop()
            queue.appendleft(tmp)
            answer += 1

    #맨 앞이 정답
    queue.popleft()
    tail_index = len(queue)-1

print(answer)
