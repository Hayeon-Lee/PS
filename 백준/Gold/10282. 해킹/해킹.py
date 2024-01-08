import sys
import heapq

input = sys.stdin.readline

def dijkstra(start, distances, graph):
    heapq.heappush(heap, [start, 0])
    distances[start] = 0

    while heap:
        current_destination, current_distance = heapq.heappop(heap)

        if current_distance > distances[current_destination]: continue

        for new_destination, new_distance  in graph[current_destination]:
            tmp_distance = current_distance + new_distance
            if tmp_distance < distances[new_destination]:
                distances[new_destination] = tmp_distance
                heapq.heappush(heap, [ new_destination, tmp_distance])

inf = sys.maxsize
test = int(input()) #test case

for _ in range(test):
    n, d, c = map(int, input().split()) #컴퓨터 개수, 의존성 개수, 해킹컴퓨터
    distances = [inf] * (n+1)
    graph = [[] for _ in range(n+1)] #그래프
    heap = []

    for _ in range(d):
        a, b, s = map(int, input().split()) 
        graph[b].append([a, s])

    dijkstra(c, distances, graph)

    computers = 0
    times = 0
    for distance in distances:
        if distance != inf:
            computers += 1
            times = max(times, distance)
    
    print(f"{computers} {times}")

'''
#다익스트라 구현 연습
def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0 
    queue = []

    heapq.heappush(queue, [distances[start], start])

    while queue:
        current_distance, current_destination = heapq.heappop(queue)

        if distances[current_destination] < current_distance:
            continue

        for new_destination, new_distance in graph[current_destination].items():
            distance = current_distance + new_distance
            if distance < distances[new_destination]:
                distances[new_destination] = distance
                heapq.heappush(queue, [distance, new_destination])
'''