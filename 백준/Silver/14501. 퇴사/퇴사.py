import sys
input = sys.stdin.readline

n = int(input())
counseling = []
for i in range(n):
    counseling.append(tuple(map(int, input().split())))

dp = [0] * (n+1)

for i in range(n):
    for j in range(i + counseling[i][0], n+1):
        if dp[j] < dp[i] + counseling[i][1]:
            dp[j] = dp[i] + counseling[i][1]

print(dp[-1])