def solution(numbers):
    
    total = []
    
    for i in range(0, len(numbers)):
        for j in range(i+1, len(numbers), 1):
                total.append(numbers[i] + numbers[j])
    
    answer = list(set(total))
    answer.sort()
    
    return answer
