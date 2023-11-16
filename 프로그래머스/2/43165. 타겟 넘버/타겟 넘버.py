def solution(numbers, target):
    answer = 0
    calculations = [0]
    
    for num in numbers:
        tmp = []
        for parent in calculations:
            tmp.append(parent+num)
            tmp.append(parent-num)
        calculations = tmp
    
    for c in calculations:
        if target == c: answer += 1
    
    return answer