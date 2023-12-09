from collections import deque

def solution(maps):
    global queue
    queue = deque()

    n = len(maps)
    m = len(maps[0])
    
    #상하좌우
    x = [-1, 1, 0, 0]
    y = [0, 0, -1, 1]
    queue.append([0,0])
    
    def bfs():
        global queue
        
        while(queue):
            arr = queue.popleft()
            nowx = arr[0]
            nowy = arr[1]
            
            if nowx == n-1 and nowy == m-1:
                break
            
            for i in range(4):
                nx = nowx + x[i]
                ny = nowy + y[i]
                
                if 0 <= nx <= n-1 and 0 <= ny <= m-1:
                    if maps[nx][ny] == 1:
                        maps[nx][ny] = maps[nowx][nowy] + 1
                        queue.append([nx, ny])

    bfs()
    if maps[n-1][m-1] == 1: return -1
    else: return maps[n-1][m-1]