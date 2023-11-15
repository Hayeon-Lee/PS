import sys
input = sys.stdin.readline

N = int(input())
serials = []

for i in range(N):
    number = input().strip()
    serials.append(number)

def plus(x):
    total = 0
    for i in range(len(x)):
        if '0' <= x[i] <= '9': 
            total += int(x[i])
    return total

serials.sort(key = lambda x: (len(x), plus(x), x))
for s in serials:
    print(s)