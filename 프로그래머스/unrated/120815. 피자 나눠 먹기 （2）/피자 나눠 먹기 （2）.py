def solution(n):
    
    i = 1
    answer = 0
    
    while(True):
        if (n*i) % 6 == 0: 
            answer = ((n*i)//6)
            break
        i+=1
    
    return answer