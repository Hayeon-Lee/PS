def solution(people, limit):
    answer = 0
    people_sort = sorted(people)
    
    start, end = 0, len(people_sort)-1
    while start <= end:
        if people_sort[start] + people_sort[end] <= limit:
            start += 1
            end -= 1
        else:
            end -= 1
        answer += 1
    
    return answer