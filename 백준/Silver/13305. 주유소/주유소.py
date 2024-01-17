import sys
input = sys.stdin.readline

n = int(input())
length = list(map(int, input().split()))
prices = list(map(int, input().split()))

answer = 0
smallest = prices[0]
tmp_length = length[0]

for i in range(1, n):
    if i == n-1:
        answer += (smallest*tmp_length)
        break

    if prices[i] <= smallest:
        answer += (smallest * tmp_length)
        smallest = prices[i]
        tmp_length = length[i]

    else :
        tmp_length += length[i]

print(answer)