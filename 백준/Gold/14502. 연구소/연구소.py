import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

graph = []
bfs_graph = []
answer = 0

n, m = map(int, input().split())
for _ in range(n):
    tmp = list(map(int, input().split()))
    graph.append(tmp)

def bfs():
    #상, 하, 좌, 우
    global answer 
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    queue = deque(viruses[:])

    while queue:
        x,y = queue.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < n and 0 <= ny < m and bfs_graph[nx][ny] == 0:
                bfs_graph[nx][ny] = 2
                queue.append((nx, ny))

    tmp_cnt = 0
    for g in bfs_graph:
        for v in g:
            if v == 0: tmp_cnt += 1
    answer = max(answer, tmp_cnt)

def solution():
    global bfs_graph

    for wall in walls:
        bfs_graph = [g[:] for g in graph]
        for w in wall:
            wx, wy = w
            bfs_graph[wx][wy] = 1
        bfs()


viruses = []
walls = []

for i in range(n):
    for j in range(m):
        if graph[i][j] == 2: viruses.append((i,j))
        if graph[i][j] == 0: walls.append((i,j))

walls = combinations(walls, 3)
solution()
print(answer)

'''
벽을 3개 세우고, bfs
'''