import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())

relation = [[] for _ in range(n+1)]
visit = [False for _ in range(n+1)]

for i in range(m):
    r1, r2 = map(int, input().split())
    relation[r1].append(r2)
    relation[r2].append(r1)

def bfs():
    global answer, queue

    while (queue):
        now = queue.popleft()

        for r in sorted(relation[now]):
            if not visit[r]:
                answer += 1
                visit[r] = True

answer = len(relation[1])
queue = deque(relation[1])
visit[1] = True

for r in sorted(relation[1]):
    visit[r] = True

bfs()
print(answer)