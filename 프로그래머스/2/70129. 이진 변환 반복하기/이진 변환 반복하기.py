def solution(s):
    answer = []
    
    zeroCnt = 0
    calCnt = 0
    
    while(True):
        if s=='1': break
        
        for c in s:
            if c=='0': zeroCnt += 1 # 0개수 세기
        
        s = s.replace('0', '')
        s = bin(len(s))[2:] #2진수로 변환
        
        calCnt += 1
    
    answer.append(calCnt)
    answer.append(zeroCnt)
        
    return answer