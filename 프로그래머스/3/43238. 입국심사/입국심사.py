def solution(n, times):
    answer = 0
    
    left = 1
    right = max(times) * n
    
    while left <= right:
        mid = ((left + right) // 2)
        people = 0
        
        for time in times:
            people += mid // time
            
            if people >= n:
                break
        if people >= n:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return answer

'''
모르겠어서 답안을 봤는데
시간을 찾는 것이 목적이기 때문에 최소 최대를 시간값으로
'''