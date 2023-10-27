N, M = map(int, input().split())
baskets = [i for i in range(N+1)]

for order in range(M):
    i, j = map(int, input().split())
    temp = baskets[i:j+1]
    temp.reverse()
    baskets[i:j+1] = temp

for order in range(1, N+1):
    print(baskets[order], end=' ')
    