import heapq
import sys

def dijkstra(distances, graph):
    heap = []
    heapq.heappush(heap, (0, 1))
    distances[1] = 0
    
    while heap:
        dist, now = heapq.heappop(heap)
        if distances[now] < dist:
            continue
        for item in graph[now]:
            c, e = item
            cost = dist + c
            
            if cost < distances[e]:
                distances[e] = cost
                heapq.heappush(heap, (cost, e))

def solution(N, road, K):
    
    distances = [sys.maxsize] * (N+1)
    graph = [[] * (N+1) for _ in range(N+1)]

    for r in road:
        s, e, c = r
        graph[s].append((c,e))
        graph[e].append((c,s))
    
    dijkstra(distances, graph)
    
    answer = 0
    for distance in distances[1:]:
        if distance <= K:
            answer += 1
    
    return answer