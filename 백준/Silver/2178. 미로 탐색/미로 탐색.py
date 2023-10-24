import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution(x, y):
    global dist, queue

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >= 0 and ny >= 0 and nx < N and ny < M:
            if maze[nx][ny] and not visit[nx][ny]:
                visit[nx][ny] = 1
                dist[nx][ny] = dist[x][y]+1
                queue.append([nx, ny])
    
    if len(queue)!=0:
        fx, fy = queue[0][0], queue[0][1]
        queue.pop(0)
        solution(fx, fy)


N, M = map(int, input().split())
maze = list()
queue = list()
visit = [[0 for _ in range(M)] for _ in range(N)]
dist = [[0 for _ in range(M)] for _ in range(N)]

#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    row = list(map(int, input().strip()))
    maze.append(row)

visit[0][0] = 1
dist[0][0] = 1
solution(0,0)
print(dist[N-1][M-1])