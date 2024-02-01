import sys
import heapq

def dijkstra(distances, graph):
    heap = []
    heapq.heappush(heap, (0, 1)) #초기값 
    distances[1] = 0
    
    while heap:
        now_cost, now_dest  = heapq.heappop(heap)
        
        for item in graph[now_dest]:
            next_cost, next_dest = item
            
            new_cost = (now_cost + next_cost) #거쳐갔을 때 비용 
            
            if new_cost < distances[next_dest]:
                distances[next_dest] = new_cost
                heapq.heappush(heap, (new_cost, next_dest))
            

def solution(N, road, K):
    distances = [sys.maxsize] * (N+1)
    graph = [[] for _ in range(N+1)]
    
    for r in road:
        s, e, c = r
        graph[s].append((c, e))
        graph[e].append((c, s))
        
    dijkstra(distances, graph)
        
    answer = 0
    for distance in distances:
        if distance <= K:
            answer += 1
        
    return answer