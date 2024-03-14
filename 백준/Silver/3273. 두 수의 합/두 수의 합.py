n = int(input())
arr = sorted(list(map(int, input().split())))
x = int(input())

answer = 0
tmp_start = 0
tmp_end = n-1

while tmp_start < tmp_end:
    tmp_sum = arr[tmp_start] + arr[tmp_end]

    if tmp_sum == x:
        answer += 1
        tmp_start += 1
    
    elif tmp_sum < x:
        tmp_start += 1

    else:
        tmp_end -= 1

print(answer)