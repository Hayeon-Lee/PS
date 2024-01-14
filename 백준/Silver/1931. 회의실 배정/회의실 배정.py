N = int(input())

arr = []

for i in range(N):
    s, e = map(int, input().split())
    arr.append([s,e])

arr = sorted(arr, key=lambda x: (x[1], x[0]))

answer = 1
small = arr[0][1]

for i in range(1, len(arr)):
    if arr[i][0] >= small:
        small = arr[i][1]
        answer += 1

print(answer)