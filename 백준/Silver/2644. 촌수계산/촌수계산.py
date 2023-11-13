import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range (n+1)]
visit = [0 for _ in range(n+1)]

target1, target2 = map(int, input().split())
t = int(input())

for i in range(t):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

def solution(target1):
    if target1 == target2:
        return
    
    for c in graph[target1]:
        if visit[c] == 0: 
            visit[c] = visit[target1] + 1
            solution(c)

visit[target1] = 0
solution(target1)

if visit[target2] == 0: print(-1)
else : print(visit[target2])
