from collections import deque

import sys
input = sys.stdin.readline

#입력 받기
n, m = map(int, input().split())

board = []
for i in range(n):
    tmp = list(map(int, input().split()))
    board.append(tmp)

moving = []
for i in range(m):
    d, s = map(int, input().split())
    moving.append((d, s))

#문제 풀이 시작
def cloud_moving(d, s):
    dx = direction_x[d-1]
    dy = direction_y[d-1]
    bug_cloud = []

    for j in range(len(cloud)):
        nx, ny = cloud[j]

        # 이동
        nx = (nx + (dx*s)) % n
        ny = (ny + (dy*s)) % n

        # 버그가 발생하는 구름 생성
        bug_cloud.append((nx, ny))
    
    return bug_cloud

def raining(bug_cloud):
    global cant_cloud
    cant_cloud = [[False]*n for _ in range(n)]

    for j in range(len(bug_cloud)):
        x, y = bug_cloud[j]
        board[x][y] += 1 #비가 내린다
        cant_cloud[x][y] = True # 구름이 사라진 칸은 구름이 생길 수 없다

def copy_bug(bug_cloud):
    bug_direction_x = [-1, -1, 1, 1]
    bug_direction_y = [-1, 1, 1, -1]

    for j in range(len(bug_cloud)):
        x, y = bug_cloud[j]
        cnt = 0

        #대각선 방향으로 거리가 1인 바구니에 물이 있는지 확인
        for k in range(4):
            nx = x + bug_direction_x[k]
            ny = y + bug_direction_y[k]

            if 0<=nx<n and 0<=ny<n:
                if board[nx][ny] > 0:
                    cnt += 1
        
        board[x][y] += cnt

def make_new_cloud():
    global cloud
    cloud = []

    for j in range(n):
        for k in range(n):
            if board[j][k] >= 2 and not cant_cloud[j][k]:
                cloud.append((j,k))
                board[j][k] -= 2


cloud = [[n-1, 0], [n-1, 1], [n-2, 0], [n-2, 1]]
cant_cloud = []

direction_x = [0, -1, -1, -1, 0, 1, 1, 1]
direction_y = [-1, -1, 0, 1, 1, 1, 0, -1]

for i in range(m):
    d, s = moving[i]

    bug_cloud = cloud_moving(d, s) #구름 이동
    raining(bug_cloud) #비 옴
    copy_bug(bug_cloud) #비바라기 스킬
    make_new_cloud() #새 구름 만들기

answer = 0 
for i in range(n):
    for j in range(n):
        answer += board[i][j]

print(answer)