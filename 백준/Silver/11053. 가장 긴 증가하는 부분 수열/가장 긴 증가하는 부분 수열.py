import sys
input = sys.stdin.readline

size = int(input())
A = list(map(int, input().split()))
longest_list= [1 for i in range(size)]

for i in range(size):
    for j in range(i):
        if A[i] > A[j]:
            longest_list[i] = max(longest_list[i], longest_list[j]+1)

print(max(longest_list))
