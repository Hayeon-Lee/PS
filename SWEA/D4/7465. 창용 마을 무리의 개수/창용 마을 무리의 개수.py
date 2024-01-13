from collections import deque

T = int(input())

def bfs(start):
    global visit

    q = deque()
    q.append(start)
    visit[start] = True

    while q:
        now = q.popleft()
        for p in graph[now]:
            if not visit[p]:
                q.append(p)
                visit[p] = True
        
for t in range(T):
    people, relationship = map(int, input().split())

    graph = [[] for _ in range(people+1)]
    visit = [False] * (people+1)
    answer = 0

    for i in range(relationship):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    for i in range(1, people+1):
        if not visit[i]:
            bfs(i)
            answer += 1

    print(f"#{t+1} {answer}")

   