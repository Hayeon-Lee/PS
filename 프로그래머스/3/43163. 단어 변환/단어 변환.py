from collections import deque

def checkSame(word, now):
    tmp = 0
    for i in range(len(word)):
        if word[i] != now[i]:
            tmp += 1
    if tmp == 1: return True
    else: return False

def solution(begin, target, words):
    
    #안에 없을 경우
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
                isSame = checkSame(words[i], now)

                if isSame and visit[i] == 0:
                    if index == -1:
                        visit[i] = 1
                    else:
                        visit[i] = visit[index]+1
                    queue.append((words[i], i))
                    
                else:
                    continue

    bfs()
    if answer_index == -1: return 0
    else: return visit[answer_index]