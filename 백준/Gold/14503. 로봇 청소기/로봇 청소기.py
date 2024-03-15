from collections import deque
n, m = map(int, input().split())

r, c, d = map(int, input().split())

# 북 동 남 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 0이면 더러움, 1이면 벽
room = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    room.append(tmp)

def solution():
    global queue, room, now_direction, answer

    while queue:
        x, y = queue.popleft()

        if room[x][y] == 0: #현재 칸이 청소가 안됐으면
            answer += 1
            room[x][y] = -1  #청소한다

        # 현재칸의 주변 4칸 중 청소되지 않은 빈칸 확인
        isClean = False    
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<m and room[nx][ny] == 0:
                isClean = True

        #청소할 곳이 있으면
        if isClean == True:
            now_direction -= 1 #반시계 방향 회전

            if now_direction < 0:
                now_direction += 4

            nx = x + dx[now_direction]
            ny = y + dy[now_direction]
            
            if room[nx][ny] == 0:
                queue.append((nx, ny))
            
            else:
                queue.append((x, y))
                
        if isClean == False: #청소되지 않은 빈 칸이 없는 경우
            nx = x+(dx[now_direction]*-1)
            ny = y+(dy[now_direction]*-1)

            if 0<=nx<n and 0<=ny<m:
                if room[nx][ny] != 1:
                    queue.append((nx,ny)) #후진 하고 1번으로 돌아간다
                    continue
                
                if room[nx][ny] == 1:
                    break #벽이라면 멈춘다

answer = 0
now_direction = d
queue = deque()
queue.append((r,c))
solution()
print(answer)
