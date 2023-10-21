import sys
sys.setrecursionlimit(150000)
input = sys.stdin.readline

N, M, R = map(int, input().split())
board = [[] for _ in range(0,N+1)] #맵
visited = [0 for _ in range(0,N+1)] #방문체크
ordered = 1
queue = list()

def solution(start):
    global ordered
    board[start].sort() #오름차순 정렬

    for i in board[start]: #지금 방문하고 있는 노드의 간선 체크
        if visited[i] == 0:
            queue.append(i) #큐에 모두 넣기
            ordered += 1
            visited[i] = ordered #방문처리
    
    if len(queue) != 0:
        next = queue[0]
        queue.pop(0)
        solution(next)

for i in range(M):
    s, e = map(int, input().split())
    board[s].append(e)
    board[e].append(s)

visited[R] = 1
solution(R)

for i in range(1, N+1, 1):
    print(visited[i])

