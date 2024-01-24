import sys
from collections import deque
input = sys.stdin.readline

#입력
n, l, r = map(int, input().split())
country = []
visit = [[False]*n for _ in range(n)]

for _ in range(n):
    tmp = list(map(int, input().split()))
    country.append(tmp)

#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

#bfs
def bfs():
    global queue, union_country, people, cnt, unions, change_value

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<n and visit[nx][ny]==False:
                diff = abs(country[x][y]-country[nx][ny])
                if l<=diff<=r:
                    visit[nx][ny] = True
                    people += country[nx][ny]
                    cnt += 1
                    union_country.append((nx,ny))
                    queue.append((nx, ny))

    if len(union_country)>1: 
        unions.append(union_country) #움직여야 할 연합국
        change_value.append(people//cnt) #바뀔 값

#인구이동
def moving():
    while unions:
        moving_deque = unions.popleft()
        value = change_value.popleft()

        while moving_deque:
            x, y = moving_deque.popleft()    
            country[x][y] = value


queue = deque()
union_country = deque()
unions = deque()

change_value = deque()
people = 0 #총 국민 수
cnt = 0 #나라 수
flag = 1

answer = 0

while True:
    for i in range(n):
        for j in range(n):
            if visit[i][j] == False:

                people = country[i][j] #인구값
                cnt = 1 #나라 개수

                queue.append((i,j)) #bfs 큐
                union_country.append((i,j)) #연합국 큐
                visit[i][j] = True
                bfs()

                queue = deque() #초기화
                union_country = deque() #초기화 

    if unions:
        moving()
        answer += 1
        visit = [[False]*n for _ in range(n)]

    else:
        break

print(answer)