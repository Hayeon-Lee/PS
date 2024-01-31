import math

def solution(n, stations, w):
    answer = 0
    rest = []
    
    before_end = 0
    for s in stations:
        start, end = max(s-w,1), min(s+w, n)
        if not before_end:
            rest.append(start - 1)
            before_end = end
        else:
            if before_end+1 < start:
                # 안 겹치는 경우
                rest.append(start - before_end - 1)
            before_end = end
                
    rest.append(n-before_end)
    
    for r in rest:
        cover = 1 + 2 * w
        answer += math.ceil(r / cover)

    return answer