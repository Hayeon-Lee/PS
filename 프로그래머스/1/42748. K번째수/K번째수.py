def solution(array, commands):
    
    answer = []
    
    for command in commands:
        i, j, k = command[0], command[1], command[2]
        split_array = array[i-1:j]
        split_array.sort()
        answer.append(split_array[k-1])
        
    return answer