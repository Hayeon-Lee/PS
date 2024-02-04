def solution(n):
    answer = 0
    
    if n == 1:
        return 1
    
    else:
        for i in range(1, int(n**0.5)+1):
            if n%i == 0:
                if i*i == n:
                    answer += i
                else:
                    answer += i
                    answer += (n//i)
    
    return answer