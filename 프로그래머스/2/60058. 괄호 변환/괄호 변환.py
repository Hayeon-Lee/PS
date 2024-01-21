from collections import deque

def check(string):
    stack = deque()
    
    for s in string:
        if s=='(': 
            stack.append('(')
        else:
            if stack:
                stack.popleft()
            else:
                return False
    
    if not stack: return True
    else: return False 
    

def solution(p):
    
    if not p: 
        return p
    
    answer = ''
    count = 0
    
    for i in range(len(p)):
        
        if p[i] == '(':
            count += 1
        else:
            count -= 1
        
        if count == 0:
            
            u = p[0:i+1]
            v = p[i+1:len(p)]
            
            checkGood = check(u)
            
            if checkGood == True:
                return u + solution(v)
                
            else:
                tmp_answer = ''
                tmp_answer += '(' 
                tmp_answer += solution(v)
                tmp_answer += ')'
                
                for j in range(1, len(u)-1):
                    if u[j] == '(':
                        tmp_answer+= ')'
                    else:
                        tmp_answer += '('
                return tmp_answer    
    