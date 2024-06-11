def solution(n, t, m, p):
    
    fullStr = ''
    last = (m*t)
    
    for i in range(last+1):
        nowStr = ''
        num = i
        
        if (num == 0):
            nowStr = '0'
            
        else:
            while num > 0:
                num, remainder = divmod(num, n)
                
                if remainder >= 10:
                    nowStr = chr(ord('A') + remainder - 10) + nowStr
                else:
                    nowStr = str(remainder) + nowStr
        fullStr += nowStr

    answer = ''
    nowIndex = p-1
    
    for i in range(0, t):
        answer += fullStr[nowIndex + (m*i)]
    
    return answer