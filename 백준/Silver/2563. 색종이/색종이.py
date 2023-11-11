import sys
input = sys.stdin.readline

paper_count = int(input())
canvas = [[0 for _ in range(101)] for _ in range(101)]

answer = 0

for i in range(paper_count):
    x, y = map(int, input().split())
    
    for j in range(x, x+10):
        for k in range(y, y+10):
            if canvas[j][k] != 1: 
                canvas[j][k] = 1
                answer += 1

print(answer)
