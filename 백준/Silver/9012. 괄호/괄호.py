import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    stack = []
    string = input().strip()
    flag = 0

    for s in string:
        if s == '(':
            stack.append('(')
        else:
            if not stack: 
                flag = 1
                print('NO')
                break
            else:
                stack.pop()
    
    if flag == 0:
        if not stack: print('YES')
        else: print('NO')