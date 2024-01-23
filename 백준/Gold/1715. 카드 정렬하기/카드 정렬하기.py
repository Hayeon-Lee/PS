import sys
import heapq
input = sys.stdin.readline

n = int(input())
card = []

for _ in range(n): 
    tmp = int(input())
    heapq.heappush(card, tmp)

answer = 0

while len(card)>=2:
    n1 = heapq.heappop(card)
    n2 = heapq.heappop(card)
    add = n1+n2

    answer += add
    heapq.heappush(card, add)

print(answer)


'''
'''