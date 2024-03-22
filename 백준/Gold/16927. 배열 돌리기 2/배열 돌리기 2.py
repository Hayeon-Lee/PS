import sys
from collections import deque

input = sys.stdin.readline

n, m, r = map(int, input().split())

arr = []
answer = [[0]*m for _ in range(n)]
queue = deque()

for i in range(n):
    arr.append(list(input().split()))

repeat = min(n, m) // 2
for i in range(repeat):
    queue.clear()
    queue.extend(arr[i][i:m-i])
    queue.extend([row[m-i-1] for row in arr[i+1:n-i-1]])
    queue.extend(arr[n-i-1][i:m-i][::-1])
    queue.extend([row[i] for row in arr[i+1:n-i-1]][::-1])
    
    queue.rotate(-r)
    
    for j in range(i, m-i):                 # 위쪽
        answer[i][j] = queue.popleft()
    for j in range(i+1, n-i-1):             # 오른쪽
        answer[j][m-i-1] = queue.popleft()
    for j in range(m-i-1, i-1, -1):           # 아래쪽
        answer[n-i-1][j] = queue.popleft()  
    for j in range(n-i-2, i, -1):           # 왼쪽
        answer[j][i] = queue.popleft()    

for line in answer:
    print(" ".join(line))