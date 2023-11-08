import sys
input = sys.stdin.readline

N = int(input())
array = [0 for _ in range(1000001)]

array[0] = 1
array[1] = 2

for i in range(2, N):
    array[i] = (array[i-2]+array[i-1])%15746

print(array[N-1])
