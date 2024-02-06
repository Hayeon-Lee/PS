import heapq

def solution(food_times, k):
    if sum(food_times) <= k:
        return -1
    
    heap = []
    for i in range(len(food_times)):
        heapq.heappush(heap, (food_times[i], i))
    
    time = 0
    length = len(food_times)
    
    while (heap[0][0] - time) * length < k:
        k -= (heap[0][0] - time) * length
        time += (heap[0][0] - time)
        length -= 1
        heapq.heappop(heap)
        
    answer = sorted(heap, key=lambda x: x[1])
    answer = answer[k%length][1] + 1
    
    return answer
            