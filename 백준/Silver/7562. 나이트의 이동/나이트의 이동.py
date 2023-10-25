import sys
input = sys.stdin.readline

dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]

def solution():
    global queue, visit, chess

    while(len(queue)):
        x, y = queue.pop(0)

        if x == want_x and y == want_y:
            print(chess[x][y])
            break

        for i in range(8):
            nx = x+dx[i]
            ny = y+dy[i]

            if nx >= 0 and nx < l and ny >= 0 and ny < l:
                if not visit[nx][ny]:
                    visit[nx][ny] = True
                    chess[nx][ny] = chess[x][y] + 1
                    queue.append([nx, ny])


test_case = int(input())

for t in range(test_case):
    l = int(input())

    chess = [[0 for _ in range(l)] for _ in range(l)]
    visit = [[False for _ in range(l)] for _ in range(l)]
    queue = list()

    now_x, now_y = map(int, input().split())
    want_x, want_y = map(int, input().split())

    visit[now_x][now_y] = True
    queue.append([now_x, now_y])
    solution()