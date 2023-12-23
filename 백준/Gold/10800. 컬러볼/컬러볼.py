import sys
input = sys.stdin.readline

n = int(input())
ball = [[0, 0, i] for i in range(n)]
ans = [0 for i in range(n)]
for i in range(n):
    ball[i][1], ball[i][0] = map(int, input().split())  # 크기가 먼저오게 담는다

ball.sort()
# 크기, 색상, 인덱스

colors = [0 for i in range(n+1)]
s = 0
j = 0
for i in range(n):
    while ball[j][0] < ball[i][0]:
        colors[ball[j][1]] += ball[j][0]
        s += ball[j][0]
        j += 1

    ans[ball[i][2]] = s - colors[ball[i][1]]

for i in range(n):
    print(ans[i])

'''
color가 같으면 잡아먹을 수 없음
color가 다르고 크기는 커야 함

크기별로 정렬후 누적
컬러별로 정렬후 누적 (인덱스 순)

내 크기에서 내 색깔 내 위치까지의 누적합을 빼기
'''