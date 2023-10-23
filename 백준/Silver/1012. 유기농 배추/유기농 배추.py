import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution(l, v):
    #상
    if l+x[0] >= 0:
        next_x = l+x[0]
        next_y = v+y[0]
        if board[next_x][next_y] and not visit[next_x][next_y]:
            visit[next_x][next_y] = 1
            solution(next_x, next_y)

    #하    
    if l+x[1] < N:
        next_x = l+x[1]
        next_y = v+y[1]
        if board[next_x][next_y] and not visit[next_x][next_y]:
            visit[next_x][next_y] = 1
            solution(next_x, next_y)

    #좌
    if v+y[2] >= 0:
        next_x = l+x[2]
        next_y = v+y[2]
        if board[next_x][next_y] and not visit[next_x][next_y]:
            visit[next_x][next_y] = 1
            solution(next_x, next_y)

    #우
    if v+y[3] < M:
        next_x = l+x[3]
        next_y = v+y[3]
        if board[next_x][next_y] and not visit[next_x][next_y]:
            visit[next_x][next_y] = 1
            solution(next_x, next_y)     

    return        


cnt = 0
#상하좌우
x = [-1, 1, 0, 0]
y = [0, 0, -1, 1]

T = int(input())

for i in range(T):
    M, N, K = map(int, input().split())
    board = [[0 for _ in range(M)] for _ in range(N)]
    visit = [[0 for _ in range(M)] for _ in range(N)]

    for j in range(K):
        a, b = map(int, input().split())
        board[b][a] = 1

    for l in range(N):
        for v in range(M):
            if board[l][v] and not visit[l][v]:
                solution(l, v)
                cnt+=1
    
    print(cnt)
    cnt = 0