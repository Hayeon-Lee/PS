from itertools import permutations
import sys

N = int(input())
nums = list(map(int, input().split()))
tmp = list(map(int, input().split()))

# +, -, *, /
op_num = '+' * tmp[0] + '-' * tmp[1] + '*' * tmp[2] + '/' * tmp[3]
op = [i for i in op_num]
op = permutations(op, N - 1) # 순열
op = list(set(op)) # 중복 제거

max = -sys.maxsize
min = sys.maxsize

for i in op:
    result = nums[0]
    for j in range(N - 1):
        if i[j] == '+':
            result += nums[j + 1]
        elif i[j] == '-':
            result -= nums[j + 1]            
        elif i[j] == '*':
            result *= nums[j + 1]
        else: # 나눗셈
            if result < 0:
                result *= -1
                result //= nums[j + 1]
                result *= -1
            else:
                result //= nums[j + 1]
    if result >= max:
        max = result
    if result < min:
        min = result

print(max)
print(min)