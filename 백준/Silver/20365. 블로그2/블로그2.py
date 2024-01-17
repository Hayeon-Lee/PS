import sys
input = sys.stdin.readline

n = int(input())
checks = input().strip()

red_points = []
blue_points = []
#파란색 시작점 체크
for i in range(0, n):
    if checks[i] == 'B': 
        blue_points.append(i)
        break

#빨간색 시작점 체크
for i in range(0, n):
    if checks[i] == 'R': 
        red_points.append(i)
        break

#파란색 끝점 체크
for i in range(n-1, -1, -1):
    if checks[i] == 'B':
        blue_points.append(i)
        break

#빨간색 끝점 체크
for i in range(n-1, -1, -1):
    if checks[i] == 'R':
        red_points.append(i)
        break

if not blue_points or not red_points:
    answer = 1
    print(answer)
    exit(0)

else:
    blue_length = blue_points[1]-blue_points[0]+1
    red_length = red_points[1]-red_points[0]+1

answer = 0
if blue_length >= red_length:

    #가장 긴 부분
    red_counts = checks[blue_points[0]:blue_points[1]+1].split('B')
    for r in red_counts:
        if r != '': answer +=1 

    #긴 부분 앞
    red_counts = checks[0:blue_points[0]].split('B')
    for r in red_counts:
        if r != '': answer+=1

    #긴 부분 뒤
    red_counts = checks[blue_points[1]:len(checks)].split('B')
    blue_counts = checks[blue_points[1]:len(checks)].split('R')
    for r in red_counts:
        if r != '': answer +=1
    for b in blue_counts:
        if b != '' : answer += 1
    
else:

    #가장 긴 부분
    blue_counts = checks[red_points[0]:red_points[1]+1].split('R')
    for b in blue_counts:
        if b != '': answer +=1

    #긴 부분 앞
    blue_counts = checks[0:red_points[0]].split('R')
    for b in blue_counts:
        if b != '': answer += 1
    
    #긴 부분 뒤
    red_counts = checks[red_points[1]:len(checks)].split('B')
    blue_counts = checks[red_points[1]:len(checks)].split('R')
    for r in red_counts:
        if r != '' : answer += 1
    for b in blue_counts:
        if b != '' : answer += 1


print(answer)