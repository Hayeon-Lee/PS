import sys
input = sys.stdin.readline

arr_2d = []

for i in range(5):
    arr_1d = input().strip()
    arr_2d.append(arr_1d)

for w in range(15):
    for h in range(5):
        length = len(arr_2d[h])
        if w < length: print(arr_2d[h][w], end = '')