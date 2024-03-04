from itertools import combinations

n = int(input())
group = []

for i in range(n):
    tmp = list(map(int, input().split()))
    group.append(tmp)

member = [i for i in range(1, n+1)]
start_team = combinations([i for i in range(1, n+1)], n//2)

answer = 1e9
for st in start_team:
    start, link = 0, 0

    lt = list(set(member) - set(st))

    for s in combinations(st, 2):
        start += group[s[0]-1][s[1]-1]
        start += group[s[1]-1][s[0]-1]

    for l in combinations(lt, 2):
        link += group[l[0]-1][l[1]-1]
        link += group[l[1]-1][l[0]-1]

    answer = min(answer, abs(start-link))

print(answer)