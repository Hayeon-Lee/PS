import sys
input = sys.stdin.readline

T = int(input())

for i in range(T):
    N = int(input())
    answer = 1
    ranks = {}

    for j in range(N):
        resume, interview = map(int, input().split())
        ranks[resume] = interview

    ranks = sorted(ranks.items())
    top = 0

    for j in range(1, len(ranks), 1):
        if ranks[j][1] < ranks[top][1]:
            answer += 1
            top = j

    print(answer)