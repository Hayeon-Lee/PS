from collections import deque
import sys
input = sys.stdin.readline

#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def solution():
    global tomato_box, deque
        
    while (deque):
        h, w = deque.popleft()

        for i in range(4):
            nx = h + dx[i]
            ny = w + dy[i]

            if 0 <= nx < height and 0 <= ny <width and tomato_box[nx][ny] == 0:
                deque.append([nx, ny])
                tomato_box[nx][ny] = tomato_box[h][w]+1

width, height = map(int, input().split())

tomato_box = list()
deque= deque()
max_day = 0

for h in range(height):
    width_list = list(map(int,input().split(' ')))
    tomato_box.append(width_list)

for h in range(height):
    for w in range(width):
        if tomato_box[h][w] == 1:
            deque.append([h, w])

solution()

for h in tomato_box:
    for w in h:
        if w == 0:
            print(-1)
            exit()
    
    max_day = max(max_day, max(h))

print(max_day-1)