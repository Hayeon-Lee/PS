#방향 정의 아이디어 구글링으로 얻음 

dx = [0, 1, 0, -1] #우하좌상 
dy = [1, 0, -1, 0] #우하좌상

#우: 0, 하: 1, 좌:2, 상: 3
direction = {
    1:[[0], [1], [2], [3]], #우,하,좌,상
    2:[[0, 2], [1, 3]],#좌우, 상하
    3:[[0, 3], [0, 1], [1, 2], [2, 3]], #상우, 우하, 하좌, 좌상
    4:[[0, 2, 3], [0, 1, 3], [0, 1, 2], [1, 2, 3]], #좌상우, 상우하, 우하좌, 상좌하
    5:[[0, 1, 2, 3]]} #사방위  

n, m = map(int, input().split())
office = []
cctv = []

for i in range(n):
    tmp = list(map(int, input().split()))
    office.append(tmp)

for i in range(n):
    for j in range(m):
        if office[i][j] != 6 and office[i][j] != 0:
            cctv.append((office[i][j], i, j))

def count(copy_office):
    global answer
    
    tmp = 0
    for i in range(n):
        for j in range(m):
            if copy_office[i][j] == 0:
                tmp += 1
    
    answer = min(answer, tmp)

def check(copy_office, nx, ny, d):
    for r in d:
        x, y = nx, ny

        while True:
            x += dx[r]
            y += dy[r]

            if 0<=x<n and 0<=y<m:
                if copy_office[x][y]==0:
                    copy_office[x][y] = '#'
                if copy_office[x][y]==6:
                    break
            else:
                break
            
def solution(office, depth):
    copy_office = [o[:] for o in office]

    if depth == len(cctv):
        count(copy_office)
        return
    
    camera, nx, ny = cctv[depth]

    for d in direction[camera]:
        check(copy_office, nx, ny, d)
        solution(copy_office, depth+1)
        copy_office = [o[:] for o in office]

answer = n*m 
solution(office, 0)
print(answer)
