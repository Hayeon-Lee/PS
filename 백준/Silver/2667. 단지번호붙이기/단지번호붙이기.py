import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution(i, j):
    
    global cnt

    for order in range(4):
        new_x = i+x[order]
        new_y = j+y[order]
        if new_x >= 0 and new_x < N and new_y >= 0 and new_y < N :
            if board[new_x][new_y] and not visit[new_x][new_y]:
                cnt += 1 #개수 세기
                visit[new_x][new_y] = 1 #방문 처리
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