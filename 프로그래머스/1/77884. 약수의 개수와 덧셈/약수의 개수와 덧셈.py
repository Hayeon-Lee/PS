def solution(left, right):
    answer = 0
    
    for i in range(left, right+1, 1):
        tmp = 0
        for j in range(1, i+1):
            if i%j == 0: tmp += 1
        if tmp % 2 == 0: answer += i
        else: answer -= i
    
    return answer