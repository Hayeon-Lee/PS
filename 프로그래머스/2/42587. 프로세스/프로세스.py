from collections import deque

def solution(priorities, location):
    priority_list = sorted(priorities, reverse=True) #우선순위 중복 없이 저장
    priority_queue = deque(priority_list)
    
    indexes = [i for i in range(len(priorities))]
    priority_and_location = deque(list(zip(priorities, indexes))) #(우선순위, 인덱스) 가 저장된 큐로 만들기
    
    answer = 0
    
    while priority_and_location:
        (p, i) = priority_and_location.popleft()
        top_priority = priority_queue[0]
        
        if p == top_priority:
            answer += 1
            priority_queue.popleft()
            if i == location:
                return answer
            
        else:
            priority_and_location.append((p, i))
                