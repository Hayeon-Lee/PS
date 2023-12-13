from collections import deque
def solution(begin, target, words):

    if target not in words:
        return 0
    
    global visit, queue, answer_index
    
    visit = [0 for _ in range(len(words))]
    queue = deque()
    queue.append((begin, -1))
    answer_index = -1
    
    def bfs():
        global visit, queue, answer_index
        while queue:
            now, index = queue.popleft()
            
            if now == target:
                answer_index = index
                
            for i in range(len(words)):
                isDiffCount = 0
                
                for j in range(len(words[i])):
                    if words[i][j] != now[j]: isDiffCount+=1
                
                if isDiffCount == 1 and visit[i] == 0:
                    if index == -1:
                        visit[i] = 1
                    else:
                        visit[i] = visit[index]+1
                    queue.append((words[i], i))

    bfs()
    if answer_index == -1: return 0
    else: return visit[answer_index]