import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    
    while (len(scoville)>=2):
        food1 = heapq.heappop(scoville)
        if (food1 >= K) : break

        food2 = heapq.heappop(scoville)
        new_food = (food1 + (food2 * 2))

        heapq.heappush(scoville, new_food)
        answer += 1

    if len(scoville) <= 1:
        if scoville[0] < K: return -1
    
    return answer