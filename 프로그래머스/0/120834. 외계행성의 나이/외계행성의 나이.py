def solution(age):
    string = 'abcdefghij'
    agearr = str(age)
    answer = ''
    
    for a in agearr:
        answer += string[int(a)]
    
    return answer
    