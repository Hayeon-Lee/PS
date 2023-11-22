'''
모든 글자가 A일 때가 최소 -> 이게 핵심
연속된 A의 길이, A의 왼쪽? A의 오른쪽? 어디서 시작할지?
'''
def solution(name):
    
    updown_cnt = 0 #상하, 알파벳이동, 전부 A일 때 0
    rightleft_cnt = len(name)-1 #좌우, 커서이동, 전부 A일 때 0
    
    for index, n in enumerate(name):
        
        #현재 위치의 알파벳을 만들기 위해 얼마나 움직여야 하는지
        updown_cnt += min(ord(n)-ord('A'), ord('Z')-ord(n)+1)
        
        #다음 글자 부터 연속된 A 찾기
        next = index + 1
        while next < len(name) and name[next] == 'A': next += 1
        
        rightleft_cnt = min([ rightleft_cnt, 2 * index + len(name) - next, index + 2 * (len(name) - next) ])
        
        
    answer = updown_cnt + rightleft_cnt    
    return answer