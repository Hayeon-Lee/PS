import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

m = int(input())
sums = [arr[0]]

#누적합 배열
for i in range(1, n):
    sums.append(arr[i]+sums[-1])

#더하기
for i in range(m):
    start, end = map(int, input().split())
    
    if start == 1:
        print(sums[end-1])

    else:
        print(sums[end-1]-sums[start-2])
