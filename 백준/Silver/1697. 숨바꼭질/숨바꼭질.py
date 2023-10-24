import sys 
input = sys.stdin.readline
MAX = 10**5 + 1
dist = [0 for _ in range(MAX)]
queue = list()

def solution():
    global queue

    queue.append(N)

    while queue:
        now = queue.pop(0)
        if now == K:
            print(dist[K])
            break

        for nx in (now+1, now-1, now*2):
            if 0 <= nx < MAX and not dist[nx]:
                dist[nx] = dist[now]+1
                queue.append(nx)

N, K = map(int, input().split())

solution()

