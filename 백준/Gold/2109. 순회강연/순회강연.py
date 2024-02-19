n = int(input())
day = [0] * 10001
university = []

for i in range(n):
    p, d = map(int, input().split())
    university.append((p,d))

university = sorted(university, key=lambda x:(-x[0], x[1]))
for u in university:
    p, d = u
    for i in range(d, 0, -1):
        if day[i] == 0:
            day[i] = p
            break

print(sum(day))