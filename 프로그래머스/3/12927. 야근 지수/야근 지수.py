import heapq

def solution(n, works):
    heap = []

    for work in works:
        heapq.heappush(heap, work*-1)

    while heap:
        if heap[0] == 0 or n == 0:
            break

        now = abs(heapq.heappop(heap))
        now -= 1
        n -= 1

        if now != 0:
            heapq.heappush(heap, now*-1)

    if not heap:
        return 0
    else:
        answer = 0
        for h in heap:
            answer += h**2
        return answer