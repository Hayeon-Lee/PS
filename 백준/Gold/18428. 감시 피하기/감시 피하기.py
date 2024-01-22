import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

n = int(input())
graph = []

for i in range(n):
    tmp = list(map(str, input().strip().split(' ')))
    graph.append(tmp)

teachers = []
students = []
nulls = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 'T':
            teachers.append((i,j))
        if graph[i][j] == 'X':
            nulls.append((i,j))
        if graph[i][j] == 'S':
            students.append((i,j))

nulls = combinations(nulls, 3)

def bfs():
    global graph
    bfs_queue = deque(teachers[:])

    while bfs_queue:
        nowx, nowy = bfs_queue.popleft() #2,2
        
        #위쪽
        for i in range(nowx, -1, -1):
            if graph[i][nowy] == 'O': break
            if graph[i][nowy] == 'S': graph[i][nowy] = 'T'

        #아래쪽
        for i in range(nowx, n, 1):
            if graph[i][nowy] == 'O': break
            if graph[i][nowy] == 'S': graph[i][nowy] = 'T'

        #왼쪽
        for i in range(nowy, -1, -1):
            if graph[nowx][i] == 'O': break
            if graph[nowx][i] == 'S': graph[nowx][i] = 'T'  

        #오른쪽
        for i in range(nowy, n, 1):
            if graph[nowx][i] == 'O': break
            if graph[nowx][i] == 'S': graph[nowx][i] = 'T'

    
for null in nulls:
    for index in null:
        x, y = index
        graph[x][y] = 'O'

    bfs()

    flag = 0
    for s in students:
        x, y = s
        if graph[x][y] != 'S':
            graph[x][y] = 'S'
            flag = 1
    
    if flag == 0:
        print("YES")
        exit()
    
    for index in null:
        x, y = index
        graph[x][y] = 'X'
    
print('NO')