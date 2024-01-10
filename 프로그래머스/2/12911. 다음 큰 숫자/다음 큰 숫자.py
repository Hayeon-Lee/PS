def solution(n):
    answer = 0
    
    binary_n = bin(n)[2:]
    cnt1 = binary_n.count('1')
    
    m = n + 1
    
    while True:
        binary_m = bin(m)[2:]
        if cnt1 == binary_m.count('1'):
            answer = m
            break
        else:
            m += 1
    
    return answer