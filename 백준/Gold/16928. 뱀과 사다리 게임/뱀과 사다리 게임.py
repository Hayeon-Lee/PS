import sys
from collections import deque
input = sys.stdin.readline

board = [i for i in range(101)]
visit = [0 for _ in range(101)]

n, m = map(int, input().split())
queue = deque()
dict = {}

def solution():
    while(len(queue)):
        now = queue.popleft()

        if now == 100:
            print(visit[now])
            return
    
        for i in range(1, 7):
            next = now+i
            if 1<=next<=100 and not visit[next]:
                if next in dict.keys():
                    next = dict[next]
                if not visit[next]:
                    visit[next] = visit[now]+1
                    queue.append(next)

for i in range(n+m):
    start, end = map(int, input().split())
    dict[start] = end

queue.append(1)
solution()