def solution(numbers):
    compare = [0 for _ in range(10)]
    
    for n in numbers:
        compare[n] += 1
    
    answer = 0
    for i in range(10):
        if compare[i] == 0: answer += i
    return answer