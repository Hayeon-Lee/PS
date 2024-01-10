def solution(n):
    
    if n == 2: return 1
    if n == 3: return 2
    
    num1 = 1
    num2 = 2
    
    for i in range(4, n+1):
        current_n = num1 + num2 
        num1 = num2
        num2 = current_n
    
    answer = current_n%1234567
    return answer