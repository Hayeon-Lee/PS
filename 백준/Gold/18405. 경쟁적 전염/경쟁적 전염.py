import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split()) #맵 크기, 바이러스 종류의 개수
graph = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    graph.append(tmp)
s, x, y = map(int, input().split()) #시간, 좌표(x,y)

#초기 바이러스 위치 저장
virus = []
for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            virus.append((graph[i][j], i, j, 0))
virus.sort()
virus = deque(virus)

#bfs
#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    while virus:
        vn, vx, vy, vt = virus.popleft()
        if vt == s:
            break

        for i in range(4):
            nx = vx + dx[i]
            ny = vy + dy[i]

            if 0<=nx<n and 0<=ny<n and graph[nx][ny] == 0:
                graph[nx][ny] = vn
                virus.append((vn, nx, ny, vt+1))
                
bfs()
print(graph[x-1][y-1])
