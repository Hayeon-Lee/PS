import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
MAX_NUM = 100001

def solution():
    global queue

    while len(queue)!=0:

        now = queue[0]
        queue.pop(0)

        if now == K:
            return
        
        if now + 1 < MAX_NUM and not visit[now+1]:
            visit[now+1] = 1
            queue.append(now+1)
            board[now+1] = board[now]+1
        
        if now - 1 >= 0 and not visit[now-1]:
            visit[now-1] = 1
            queue.append(now-1)
            board[now-1] = board[now]+1
        
        if now*2 < MAX_NUM and not visit[now*2]:
            visit[now*2] = 1
            queue.append(now*2)
            board[now*2] = board[now]+1


N, K = map(int, input().split())
board = [0 for _ in range(MAX_NUM)]
visit = [0 for _ in range(MAX_NUM)]
queue = list()

board[N] = 0
visit[N] = 1
queue.append(N)
solution()
print(board[K])