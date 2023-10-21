import sys
sys.setrecursionlimit(150000)
input = sys.stdin.readline

N, M, R = map(int, input().split())
board = [[] for _ in range(0,N+1)] #맵
visited = [0 for _ in range(0,N+1)] #방문체크
ordered = 1

def solution(start):
    global ordered
    
    visited[start] = ordered #시작노드 방문체크
    board[start].sort() #오름차순 정렬

    for i in board[start]: #지금 방문하고 있는 노드의 간선 체크
        if visited[i] == 0:
            ordered += 1
            solution(i)

for i in range(M):
    s, e = map(int, input().split())
    board[s].append(e)
    board[e].append(s)

solution(R)

for i in range(1, N+1, 1):
    print(visited[i])