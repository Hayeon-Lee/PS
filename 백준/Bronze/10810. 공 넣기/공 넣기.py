N, M = map(int, input().split())

basket = [0 for _ in range(N+1)]

for order in range(M):
    i, j, k = map(int, input().split())

    for p in range(i, j+1):
        basket[p] = k

for order in range(1, N+1):
    print(basket[order], end=' ')
