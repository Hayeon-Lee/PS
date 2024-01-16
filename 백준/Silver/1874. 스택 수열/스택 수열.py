import sys
from collections import deque

input = sys.stdin.readline

queue = deque()
stack = []

n = int(input())

for i in range(n):
    tmp = int(input())
    queue.append(tmp)

index = 1
answer = []
flag = 0

while queue:
    if stack and stack[-1] == queue[0]:
        stack.pop()
        queue.popleft()
        answer.append('-')
    elif index <= queue[0]:
        while index <= queue[0]:
            stack.append(index)
            index+=1
            answer.append('+')
    else:
        flag = -1
        break

if flag==-1:
    print('NO')
else:
    for a in answer:
        print(a, end=' ')
