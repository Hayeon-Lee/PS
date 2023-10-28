import sys
from collections import deque
input = sys.stdin.readline

M, N, H = map(int, input().split())

tomatoes = list()
queue = deque()
day = 0

#2차원상하좌우, 3차원상하
dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dh = [0, 0, 0, 0, -1, 1]

def solution():
    global queue, tomatoes

    while len(queue):
        h, x, y = queue.popleft()
    
        for i in range(6):
            nh = h + dh[i]
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nh<H and 0<=nx<N and 0<=ny<M and tomatoes[nh][nx][ny]==0:
                tomatoes[nh][nx][ny] = tomatoes[h][x][y] + 1
                queue.append([nh, nx, ny])

for h in range(H):
    temp_2d = []
    for n in range(N):
        temp_1d = list(map(int, input().split(' ')))
        temp_2d.append(temp_1d)
        for m in range(M):
            if temp_1d[m] == 1:
                queue.append([h, n, m])      
    tomatoes.append(temp_2d)

solution()

for h in tomatoes:
    for n in h:
        for m in n:
            if m==0:
                print("-1")
                exit()

        day = max(day, max(n))
    
print(day-1)