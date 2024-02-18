def solution(emergency):
    dict = {}
    
    for e in emergency:
        dict[e] = 0
    
    sort_emergency = sorted(emergency, reverse = True)
    rank = 1
    
    for s in sort_emergency:
        dict[s] = rank
        rank += 1
    
    answer = []
    for e in emergency:
        answer.append(dict[e])
    
    return answer