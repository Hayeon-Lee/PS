def solution(citations):
    answer = 0
    citations.sort()
    total = len(citations)
    
    for i in range(total):
        hindex = total - i
        if citations[i] >= hindex: 
            answer = hindex
            break
            
    return answer
