import sys
input = sys.stdin.readline

nums = [0, 1, 1, 1]
for i in range(4, 101, 1):
    nums.append(nums[i-3]+nums[i-2])

T = int(input())
for i in range(T):
    N = int(input())
    print(nums[N])
