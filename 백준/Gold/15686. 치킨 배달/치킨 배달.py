'''
dfs, bfs 막 해보다가 그럴 필요 없다는 것 깨닫고 하나하나 해보고
치킨집 파업 여부 체크 사용했다가 오류 생기고 시간 오래걸리는 바람에 combinations 사용

코드 최적화는 
이 분 풀이법 참고함 -> (https://codesyun.tistory.com/185)
'''

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