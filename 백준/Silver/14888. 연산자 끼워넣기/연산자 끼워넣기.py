import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
plus, minus, multiple, divide = map(int, input().split())

max_value = -sys.maxsize
min_value = sys.maxsize

def dfs(i, now):
    global min_value, max_value, plus, minus, multiple, divide

    if i==n:
        min_value = min(min_value, now)
        max_value = max(max_value, now)
    
    else:
        if plus > 0:
            plus -= 1
            dfs(i+1, now + numbers[i])
            plus += 1
        
        if minus > 0:
            minus -= 1
            dfs(i+1, now-numbers[i])
            minus += 1
        
        if multiple > 0:
            multiple -= 1
            dfs(i+1, now*numbers[i])
            multiple += 1
        
        if divide > 0:
            divide -= 1
            dfs(i+1, int(now/numbers[i]))
            divide += 1

dfs(1, numbers[0])
print(max_value)
print(min_value)
