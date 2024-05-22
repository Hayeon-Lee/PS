def solution(arr):
    arr.sort()
    answer = arr[-1]
    
    dup = 2
    
    while True:
        flag = 0
        for i in range(0, len(arr)):
            if (answer % arr[i] != 0):
                flag = 1
                break
        if (flag == 1):
            answer = arr[-1] * dup
            dup += 1
        else: break
    
    return answer
            