import sys
input = sys.stdin.readline

def solution(start):
    global cnt
    computers[start].sort()
    for computer in computers[start]:
        if not visited[computer]:
            visited[computer] = 1 #방문처리
            cnt += 1
            solution(computer)


N = int(input())
M = int(input())
cnt = 0
computers = [[] for _ in range(N+1)]
visited = [ 0 for _ in range(N+1) ]

#입력받기
for i in range(M):
    start, end = map(int, input().split())
    computers[start].append(end)
    computers[end].append(start)

visited[1] = 1
solution(1)
print(cnt)