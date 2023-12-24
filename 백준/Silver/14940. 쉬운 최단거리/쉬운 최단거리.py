import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
board = []
queue = deque()
visit = [[0 for _ in range(m)] for _ in range(n)]

#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(n):
    tmp = list(map(int, input().split()))
    board.append(tmp)

def bfs():
    global visit, queue

    while(queue):

        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if 0<=nx<n and 0<=ny<m and visit[nx][ny] == 0 and board[nx][ny] == 1:
                visit[nx][ny] = visit[x][y] + 1
                queue.append((nx, ny))

for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            queue.append((i, j))

bfs()

for i in range(n):
    for j in range(m):
        if visit[i][j] == 0 and board[i][j] == 1:
            print(-1, end = ' ')
        else: print(visit[i][j], end = ' ')
    print()
