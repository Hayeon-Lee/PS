import sys
input = sys.stdin.readline

n = int(input())
home = sorted(list(map(int, input().split())))
print(home[(n-1)//2])

'''
1 2 3 4 5 -> 5//2 == 2, 4//2 == 2
1 2 3 4 -> 4//2 == 2, 3//2 == 1
'''