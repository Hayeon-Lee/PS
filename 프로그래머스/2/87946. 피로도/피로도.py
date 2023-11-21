def solution(k, dungeons):
    visit = [0 for _ in range(len(dungeons))]
    global answer
    answer = 0
    
    def dfs(k, cnt):
        global answer
        answer = max(cnt, answer)
        
        for i in range(len(dungeons)):
            if k >= dungeons[i][0] and visit[i] == 0:
                visit[i] = 1
                dfs(k-dungeons[i][1], cnt+1)
                visit[i] = 0
            
    dfs(k, 0)
    return answer
    
'''
모든 던전을 for로 검색하여, 갈 수 있는 경로를 다 가보기
탐색 이후에는 방문 처리를 다시 되돌린다.
'''