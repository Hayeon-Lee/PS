def solution(N, stages):
    
    state = {}
    result = {}
    
    for i in range(1, N+2):
        state[i] = 0
        result[i] = 0
    
    for s in stages:
        state[s] += 1
    
    total_person = state[N+1]
    
    for i in range(N, 0, -1):
        total_person += state[i]
        
        if total_person == 0:
            result[i] = 0
        else:
            result[i] = state[i]/total_person 
        
    result = sorted(result.items(), key=lambda x:(-x[1], x[0]))
    
    answer = []
    for r in result:
        key, value = r
        if key != N+1:
            answer.append(key)
                    
    return answer


#실패율: 도달했으나 클리어하지 못한 / 도달한 
#스테이지 개수 (N)
#도전중인 스테이지 번호 