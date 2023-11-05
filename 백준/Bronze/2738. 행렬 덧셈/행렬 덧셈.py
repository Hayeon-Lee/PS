import sys
input = sys.stdin.readline

N, M = map(int, input().split())

A = []
B = []

for i in range(N):
    tmp_1d = list(map(int, input().split()))
    A.append(tmp_1d)

for i in range(N):
    tmp_1d = list(map(int, input().split()))
    B.append(tmp_1d)

for i in range(N):
    for j in range(M):
        B[i][j] += A[i][j]
        print(B[i][j], end = ' ')
    print()