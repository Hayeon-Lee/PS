def solution(numbers):
    
    answer = 0
    for n in numbers:
        answer += n
    
    return answer/len(numbers)