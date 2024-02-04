def solution(s):
    
    pm = 1
    answer = 0
    
    if s[0] == '+' or s[0] == '-':
        if s[0] == '+':
            answer = int(s[1:])
        else:
            answer = -1 * int(s[1:])
    else:
        answer = int(s)
    
    return answer