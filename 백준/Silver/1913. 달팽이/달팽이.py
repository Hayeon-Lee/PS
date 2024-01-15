import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
answer = [[0]*N for _ in range(N)] 

#하, 우, 상, 좌 
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

direction = 0

cnt = N*N
nx = 0
ny = 0

answer_index = []

while cnt >= 1:
    if 0<=nx<N and 0<=ny<N and answer[nx][ny] == 0 :
        answer[nx][ny] = cnt
        if cnt == M:
            answer_index = [nx, ny]
        cnt -= 1
    
    x = nx+dx[direction]
    y = ny+dy[direction]

    if x<0 or x>=N or y<0 or y>=N or answer[x][y] != 0:
        direction = (direction+1)%4

    nx = nx + dx[direction]
    ny = ny + dy[direction]
    
for r in answer:
    for c in r:
        print(c, end=' ')
    print()

print(answer_index[0]+1, answer_index[1]+1)