import sys
import heapq
input = sys.stdin.readline

n = int(input())
m = int(input())

distances = [sys.maxsize] * (n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    s, e, c = map(int, input().split())
    graph[s].append((e,c))

targetS, targetE = map(int, input().split())
heap = []

def dijkstra(targetS):
    global distances, graph

    heapq.heappush(heap, (targetS, 0))
    distances[targetS] = 0

    while heap:
        current_destination, current_distance = heapq.heappop(heap)

        if current_distance > distances[current_destination]: continue

        for new_destination, new_distance in graph[current_destination]:
            tmp_distance = current_distance + new_distance
            if tmp_distance < distances[new_destination]:
                distances[new_destination] = tmp_distance
                heapq.heappush(heap, (new_destination, tmp_distance))

dijkstra(targetS)
print(distances[targetE])
