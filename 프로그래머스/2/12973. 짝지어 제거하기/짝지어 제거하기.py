from collections import deque

def solution(s):
    
    if len(s) % 2 == 1:
        return 0
    
    s = deque(s)
    queue = deque()
    
    while s:
        
        if not queue:
            if s:
                queue.append(s.popleft())
            else:
                break
            
        else:
            if s:
                if queue[0] == s[0]:
                    queue.popleft()
                    s.popleft()
                else:
                    queue.appendleft(s.popleft())   
            else: break
            
    if queue:
        return 0
    else:
        return 1
    