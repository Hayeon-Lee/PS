import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution(i, j):
    
    global cnt

    #상
    if i+x[0] >= 0:
        new_x = i+x[0]
        new_y = j+y[0]
        # 1이면서 이동 가능할 때
        if board[new_x][new_y] and not visit[new_x][new_y]:
            cnt += 1 #개수 세기
            visit[new_x][new_y] = 1 #방문 처리
            solution(new_x, new_y)
    
    #하
    if i+x[1] < N:
        new_x = i+x[1]
        new_y = j+y[1]
        #1이면서 이동 가능할 때
        if board[new_x][new_y] and not visit[new_x][new_y]:
            cnt += 1
            visit[new_x][new_y] = 1 
            solution(new_x, new_y)
    
    #좌
    if j+y[2] >= 0:
        new_x = i+x[2]
        new_y = j+y[2]
        if board[new_x][new_y] and not visit[new_x][new_y]:
            cnt += 1
            visit[new_x][new_y] = 1
            solution(new_x, new_y)

    #우
    if j+y[3] < N:
        new_x = i+x[3]
        new_y = j+y[3]
        if board[new_x][new_y] and not visit[new_x][new_y]:
            cnt += 1
            visit[new_x][new_y] = 1
            solution(new_x, new_y)

    return

#상하좌우
x = [-1, 1, 0, 0]
y = [0, 0, -1, 1]

N = int(input())
board = list()
visit = [[0 for _ in range(N)] for _ in range(N)]
cnt = 0
answer = list()

for i in range(N):
    user_input = list(map(int, input().strip()))
    board.append(user_input)

for i in range (N):
    for j in range(N):
        if board[i][j] and not visit[i][j]:
            solution(i, j)
            if (cnt == 0) :
                answer.append(1)
            else:
                answer.append(cnt)
            cnt = 0

print(len(answer))
answer.sort()
for i in answer:
    print(i)