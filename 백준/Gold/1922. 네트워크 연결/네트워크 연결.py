import sys
input = sys.stdin.readline
N = int(input())
M = int(input())

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


parent = [i for i in range(N+1)]
edges = []

for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()
result = 0
for c, a, b in edges:
    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        result += c

print(result)