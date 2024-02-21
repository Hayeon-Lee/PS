import sys
from collections import deque
input = sys.stdin.readline

n, l, r = map(int, input().split())

country = []
for i in range(n):
    tmp = list(map(int, input().split()))
    country.append(tmp)

def bfs(country, visit, check_country, total_moving_country):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    moving_country = deque()
    new_pop = 0

    while check_country:
        nx, ny = check_country.popleft()
        if new_pop == 0:
            new_pop = country[nx][ny]

        for k in range(4):
            x = nx + dx[k]
            y = ny + dy[k]

            if 0<=x<n and 0<=y<n and visit[x][y]==False:
                diff = abs(country[nx][ny] - country[x][y])
                if l <= diff <= r: 
                    visit[x][y] = True 
                    new_pop += country[x][y]

                    if len(moving_country) == 0:
                        moving_country.append((nx,ny))
                    moving_country.append((x,y)) #인구이동 해야 할 나라

                    check_country.append((x,y)) #bfs를 위해 저장하는 나라

    if len(moving_country)!=0:
        moving_country.append((new_pop//len(moving_country)))
        total_moving_country.append(moving_country)

def moving(country, total_moving_country):
    while total_moving_country:
        m_c = total_moving_country.popleft()
        popularity = m_c.pop()

        while m_c:
            cx, cy = m_c.popleft()
            country[cx][cy] = popularity

answer = 0
while True:
    visit = [[False] * (n) for _ in range(n)]
    check_country = deque()
    total_moving_country = deque()

    for i in range(n):
        for j in range(n):
            if visit[i][j] == False:
                check_country.append((i, j))
                visit[i][j] = True
                bfs(country, visit, check_country, total_moving_country)

    if total_moving_country:
        moving(country, total_moving_country)
        answer += 1

    else:
        break

print(answer)