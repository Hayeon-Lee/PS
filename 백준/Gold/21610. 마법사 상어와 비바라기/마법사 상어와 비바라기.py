import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
board = []

directions = {
    #방향: [x, y]
    1:[0, -1], #좌
    2:[-1, -1], #좌측위
    3:[-1, 0], #상
    4:[-1, 1], #우측위
    5:[0, 1], #우
    6:[1, 1], #우측아래
    7:[1, 0], #하
    8:[1, -1] #좌측아래
}

for i in range(n):
    board.append(list(map(int, input().split())))

moving_list = []
for i in range(m):
    d, s = map(int, input().split())
    moving_list.append((d,s))

def cloud_moving(d, s):
    global cloud, bug_loc

    dx = directions[d][0]
    dy = directions[d][1]

    for i in range(len(cloud)):
        nx, ny = cloud[i]

        nx = (nx + dx*s) % n 
        ny = (ny + dy*s) % n
        cloud[i][0] = nx
        cloud[i][1] = ny

        bug_loc.append((nx, ny))

def rain():
    global cloud, board, visit
    for i in range(len(cloud)):
        cx, cy = cloud[i][0], cloud[i][1]
        board[cx][cy]+=1
        visit[cx][cy] = True

def water_copy_bug():
    global board, bug_loc

    bug_dx = [-1, -1, 1, 1]
    bug_dy = [-1, 1, -1, 1]

    while bug_loc:
        bx, by = bug_loc.popleft()

        for k in range(4):
            nbx = bx + bug_dx[k]
            nby = by + bug_dy[k]

            if 0<=nbx<n and 0<=nby<n and board[nbx][nby] > 0:
                board[bx][by] += 1

def make_new_cloud():
    global board, visit, cloud

    for i in range(n):
        for j in range(n):
            if board[i][j] >= 2 and visit[i][j] == False:
                cloud.append([i, j])
                board[i][j] -= 2

cloud = [[n-1,0],[n-1,1], [n-2, 0], [n-2,1]] #초기 구름 위치

visit = [[False] * n for _ in range(n)]
bug_loc = deque()

for m_l in moving_list:
    d, s = m_l
    cloud_moving(d, s) #구름 이동
    rain() #비가 온다
    cloud = [] #구름이 모두 사라진다
    water_copy_bug()
    make_new_cloud()
    visit = [[False] * n for _ in range(n)]
    

answer = 0
for i in range(n):
    for j in range(n):
        answer += board[i][j]

print(answer)