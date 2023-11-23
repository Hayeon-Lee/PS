def solution(n):
    answer = ''
    
    while (n >= 1):
        div, mod = divmod(n, 3)
        answer += str(mod)
        n //= 3
    
    answer = int(answer, 3)
    
    return answer