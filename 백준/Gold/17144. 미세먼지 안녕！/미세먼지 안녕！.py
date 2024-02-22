import sys
from collections import deque
input = sys.stdin.readline

r, c, t = map(int, input().split())

original_room = []
room = []
cleaner = []
dust = []

for i in range(r):
    tmp = list(map(int, input().split()))

    for j in range(len(tmp)):
        if tmp[j] == -1:
            cleaner.append([i,j])

    room.append(tmp)

def bfs():
    global room, dust, original_room

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    dust = deque(dust)

    while dust:
        nx, ny = dust.popleft()
        cnt = 0
        spread = (original_room[nx][ny] // 5)

        for i in range(4):
            x = nx+dx[i]
            y = ny+dy[i]

            if 0<=x<r and 0<=y<c and room[x][y] != -1:
                cnt += 1
                room[x][y] += spread 

        original_room[nx][ny] -= (spread*cnt) # 전파 하나도 안 되면 cnt 0 되어 아무 일도 일어나지 않기 때문에, cnt가 0일 때라는 예외처리 안해도 됨
        if original_room[nx][ny] < 0:
            original_room[nx][ny] = 0

up = cleaner[0][0]
down = cleaner[1][0]

def up_cleaning():
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]
    direct = 0
    before = 0
    x, y = up, 1

    while True:
        nx = x + dx[direct]
        ny = y + dy[direct]
        if x == up and y == 0:
            break
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            direct += 1
            continue
        room[x][y], before = before, room[x][y]
        x = nx
        y = ny

def down_cleaning():
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    direct = 0
    before = 0
    x, y = down, 1
    while True:
        nx = x + dx[direct]
        ny = y + dy[direct]
        if x == down and y == 0:
            break
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            direct += 1
            continue
        room[x][y], before = before, room[x][y]
        x = nx
        y = ny

def initialize():
    global original_room, room, dust

    dust = deque()
    for x in range(r):
        for y in range(c):
            if room[x][y] > -1:
                dust.append((x,y))

    original_room = [r[:] for r in room]
    room = [[0]*c for _ in range(r)]
    room[cleaner[0][0]][cleaner[0][1]] = -1
    room[cleaner[1][0]][cleaner[1][1]] = -1

def merge_room():
    global original_room, room 

    for x in range(r):
        for y in range(c):
            if room[x][y] > -1 and original_room[x][y] > -1 :
                room[x][y] += original_room[x][y]

for i in range(t):
    initialize() #배열 초기화, 먼지위치 초기화
    bfs() #전파된다

    merge_room() # 원래 먼지랑 합치기 

    up_cleaning() # 공기청정기 가동
    down_cleaning() #공기청정기 가동

answer = 0
for i in range(r):
    for j in range(c):
        if room[i][j]>-1:
            answer += room[i][j]

print(answer)
'''
7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

8 8 10
3 0 0 0 0 0 0 0
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
'''