from collections import deque

def bfs(graph, visit, distance):
    queue = deque([1])
    visit[1] = True
    
    while queue:
        now = queue.popleft()
        
        for node in sorted(graph[now]):
            if visit[node] == False :
                distance[node] = distance[now]+1
                queue.append(node)
                visit[node] = True

def solution(n, edge):
    graph = [[] for _ in range(n+1)]
    visit = [False] * (n+1)
    distance = [0] * (n+1)
    
    for e in edge:
        start, end = e
        graph[start].append(end)
        graph[end].append(start)
    
    bfs(graph, visit, distance)
    
    distance = sorted(distance, reverse=True)
    maximum = distance[0]
    
    answer = 1
    for d in distance[1:]:
        if d == maximum:
            answer += 1
        else:
            break
    return answer