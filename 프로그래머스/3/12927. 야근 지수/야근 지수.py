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
'''
제곱을 하면 숫자가 커지기 때문에 가능한 많은 일을 적게 남겨야 한다
먼저 처리해야 할 일은 1과 0이 아닌 일들부터
'''