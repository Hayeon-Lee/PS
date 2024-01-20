import sys
from collections import deque
input = sys.stdin.readline

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n+1)]
visit = [0] * (n+1)
queue = deque()

def bfs():

    global queue, visit

    while(queue):
        start = queue.popleft()
        for v in sorted(graph[start]):
            if visit[v] == 0:
                visit[v] = (visit[start] + 1)
                queue.append(v)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

queue.append(x)
visit[x] = 1
bfs()

answer = []
for v in range(1, n+1):
    if visit[v] == k+1:
        answer.append(v)

if len(answer) == 0: print(-1)
else: 
    for a in sorted(answer): print(a)
