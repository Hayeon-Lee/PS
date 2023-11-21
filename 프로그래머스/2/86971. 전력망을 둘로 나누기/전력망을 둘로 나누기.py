from collections import deque

def solution(n, wires):
    graph = [[] for _ in range(n+1)]
    links = [[False for _ in range(n+1)] for _ in range(n+1)]
    answer = 10**6
    
    #그래프 만들기
    for wire in wires:
        first, second = wire[0], wire[1]
        graph[first].append(second)
        graph[second].append(first)
        links[first][second] = True
        links[second][first] = True
    
    #해당 그래프에 속한 기기 구하기
    def bfs(start, visit, cnt):
        queue = deque()
        queue.append(start)
        
        while(queue):
            start = queue.popleft()
            for dest in graph[start]:
                if not visit[dest] and links[start][dest] and links[dest][start]:
                    cnt += 1
                    visit[dest] = True
                    queue.append(dest)
        if cnt == 0: return 1
        else : return cnt
    
    for wire in wires:
        first, second = wire[0], wire[1]
        visit = [False for _ in range(n+1)]
        
        #와이어 끊기
        links[first][second] = False
        links[second][first] = False
        
        #개수 구하기
        a = bfs(first, visit, 0)
        b = bfs(second, visit, 0)
        
        #다시 연결하기
        links[first][second] = True
        links[second][first] = True
        
        #결과보기
        answer = min(answer, abs(a-b))
    
    return answer

'''
연결을 전부 끊어보고, 해당 노드와 연결된 송전탑의 개수를 센다
'''