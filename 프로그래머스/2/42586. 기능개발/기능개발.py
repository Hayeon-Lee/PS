from collections import deque

def solution(progresses, speeds):
    progress_queue = deque(progresses)
    speed_queue = deque(speeds)
    answer = []
    cnt = 0
    
    while(progress_queue):
        for i in range(len(progress_queue)):
            progress_queue[i] += speed_queue[i]
        
        while len(progress_queue) != 0 and progress_queue[0] >= 100:
            progress_queue.popleft()
            speed_queue.popleft()
            cnt += 1
        
        if cnt != 0:
            answer.append(cnt)
            cnt = 0
        
    return answer