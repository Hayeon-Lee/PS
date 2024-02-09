import sys
input = sys.stdin.readline

def find_high(n, benefits):
    dp = [0 for _ in range(n)]
    dp[0] = benefits[0]

    for i in range(1, n):
        dp[i] = max(dp[i-1]+benefits[i], benefits[i])

    return max(dp)

while True:
    n = int(input())
    
    if n == 0: 
        break

    else:
        benefits = []
        for i in range(n):
            m = int(input())
            benefits.append(m)
        print(find_high(n, benefits))

''' 찾은 반례
4
2
4
6
-12
0
'''

'''
더하지 않은 것
더한 것
'''