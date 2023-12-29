import sys

input = sys.stdin.readline


def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]


def union_(a, b):
    a = find(a)
    b = find(b)

    # 이미 부모가 같다면 리턴
    if a == b:
        return

    if rank[a] > rank[b]:
        parent[b] = a
    elif rank[a] < rank[b]:
        parent[a] = b
    else:
        parent[a] = b
        rank[b] += 1


N, M = map(int, input().split())

graph = []
parent = [i for i in range(N + 1)] 
rank = [0] * (N + 1)  
for i in range(M):
    a, b, cost = map(int, input().split())
    graph.append((a, b, cost))

graph.sort(key=lambda x: x[2]) 
ans = 0  
end_v = 0 
for i in graph:

    if find(i[0]) != find(i[1]):
        union_(i[0], i[1])
        ans += i[2]  
        end_v = i[2]  

print(ans - end_v)  