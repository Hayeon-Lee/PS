def solution(n, lost, reserve):
    
    lost.sort()
    reserve.sort()
    
    new_reserve = set(reserve)-set(lost) 
    new_lost = set(lost)-set(reserve)
    
    answer = n
    
    for r in new_reserve:
        if r-1 in new_lost:
            new_lost.remove(r-1)
            continue
        if r+1 in new_lost:
            new_lost.remove(r+1)
            continue
    
    answer -= len(new_lost)
    return answer