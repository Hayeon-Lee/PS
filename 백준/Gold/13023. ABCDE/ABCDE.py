import sys
input = sys.stdin.readline

n, m = map(int,input().split())
relationship = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    relationship[a].append(b)
    relationship[b].append(a)

count = [0] * n
answer = 0

def dfs(now, cnt):
    global answer, count

    if cnt == 4:
        answer = 1
        return

    for i in relationship[now]:
        if count[i] == 0:
            count[i] = 1
            dfs(i, cnt+1)
            count[i] = 0

for j in range(n):
    count[j] += 1
    dfs(j, 0)
    if answer == 1:
        break
    count[j] -= 1

print(answer)
