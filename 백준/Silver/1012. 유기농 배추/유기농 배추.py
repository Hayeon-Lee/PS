import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution(l, v):

    for order in range(4):
        next_x = l+x[order]
        next_y = v+y[order]
        if next_x >= 0 and next_x < N and next_y >= 0 and next_y < M:
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