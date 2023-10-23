import sys
input = sys.stdin.readline
sys.setrecursionlimit(150000)

def dfs(start):
    board[start].sort()

    for item in board[start]:
        if not visit[item]:
            visit[item] = 1
            print(item, end= ' ')
            dfs(item)

def bfs(start):
    board[start].sort()

    for item in board[start]:
        if not visit[item]:
            queue.append(item)
            visit[item] = 1
            print(item, end = ' ')

    if len(queue)!=0:
        next = queue[0]
        queue.pop(0)
        bfs(next)

N, M, V = map(int, input().split())
board = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]
queue = list()

for i in range(M):
    start, end = map(int,input().split())
    board[start].append(end)
    board[end].append(start)

#dfs 수행결과
visit[V] = 1
print(V, end=' ')
dfs(V)

visit = [0 for _ in range(N+1)]
print()

#bfs 수행결과
visit[V] = 1
print(V, end=' ')
bfs(V)