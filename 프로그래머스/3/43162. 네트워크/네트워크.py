def solution(n, computers):
    visit = [0 for _ in range(n)]
    answer = 0
    
    def dfs(now):
        visit[now] = 1
        
        for j in range(n):
            if computers[now][j] == 1 and not visit[j]: dfs(j)
        
    
    for i in range(n):
        if not visit[i] :
            dfs(i)
            answer += 1
    
    return answer