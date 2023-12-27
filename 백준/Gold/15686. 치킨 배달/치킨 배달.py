from itertools import combinations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
answer = 1e9
city = []
house = []
store = []

for _ in range(n): city.append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):
        if city[i][j] == 1: house.append([i,j])
        if city[i][j] == 2: store.append([i,j])

for s in combinations(store, m): #조합으로 치킨집 m개 뽑기
    length = 0

    for h in house:
        hcLength = 1e9 #집이랑 치킨집 사이 거리
        for j in range(m):
            hcLength = min(hcLength, abs(h[0]-s[j][0]) + abs(h[1]-s[j][1]))
        length += hcLength

    answer = min(answer, length)

print(answer)

'''
치킨집 좌표 구하고 하나하나 폐업시키기 -> 조합으로 고르기

방문한 곳을 관리하면서 백트래킹 하려 했으나, 조합 함수 덕에 안해도 됨
모든 곳 다 해보면서 최솟값 고르기
'''