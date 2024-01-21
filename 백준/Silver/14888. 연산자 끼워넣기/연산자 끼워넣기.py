import sys
from itertools import permutations
input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
operators_cnt = list(map(int, input().split()))
oper = ['+', '-', '*', '/']

operators = []

for i in range(len(operators_cnt)):
    for _ in range(operators_cnt[i]):
        operators.append(oper[i])

operators = list(set(permutations(operators, n-1)))

max_value = -sys.maxsize
min_value = sys.maxsize

for oper in operators:

    tmp = numbers[0]
    for i in range(n-1):
        if oper[i] == '+':
            tmp += numbers[i+1]
        elif oper[i] == '-':
            tmp -= numbers[i+1]
        elif oper[i] == '*':
            tmp *= numbers[i+1]
        else:
            if tmp < 0:
                tmp *= -1
                tmp //= numbers[i+1]
                tmp *= -1
            else:
                tmp //= numbers[i+1]
    
    if tmp >= max_value:
        max_value = tmp
    
    if tmp < min_value:
        min_value = tmp

print(max_value)
print(min_value)    
