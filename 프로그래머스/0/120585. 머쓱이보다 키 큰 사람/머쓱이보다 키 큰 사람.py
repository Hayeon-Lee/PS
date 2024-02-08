def solution(array, height):
    answer = []
    for i in array:
        if height < i:
            answer.append(i)
    return len(answer)