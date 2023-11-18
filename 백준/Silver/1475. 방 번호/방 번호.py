import sys
input = sys.stdin.readline

N = input().strip()

check = [0 for _ in range(10)]

for i in N:
    check[int(i)] += 1

flag = (check[6]+check[9])//2 + ((check[6]+check[9])%2)#6과 9는 2개가 모이면 1세트

check[6] = 0
check[9] = 0
check.sort(reverse=True)

answer = max(flag, check[0])
print(answer)