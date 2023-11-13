import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
check = [0 for _ in range(N)]

tmp = arr[0]
check[0] = arr[0]

for i in range(1, N):
    tmp += arr[i]
    if tmp < arr[i] : 
        check[i] = arr[i]
        tmp = arr[i]
    else:
        check[i] = tmp

print(max(check))