from itertools import combinations

n = int(input())
group = []

for i in range(n):
    tmp = list(map(int, input().split()))
    group.append(tmp)

team = combinations([i for i in range(1, n+1)], n//2)

answer = 1e9
for t in team:
    check = [False] * (n+1)

    start = 0 #True
    link = 0 #False

    for p in t:
        check[p] = True

    for i in range(1, n+1):
        now_team = check[i]

        for j in range(1, n+1):
            if i!=j and check[j] == now_team: #같은 팀이면
                if now_team == True:
                    start += group[i-1][j-1]
                if now_team == False:
                    link += group[i-1][j-1]
    
    answer = min(answer, abs(start-link))

print(answer)