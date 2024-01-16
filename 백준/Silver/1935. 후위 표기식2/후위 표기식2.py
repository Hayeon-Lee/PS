import sys
input = sys.stdin.readline

N = int(input())
alphabets = {}
numbers = [0] * N
expression = input().strip()

for i in range(N):
    numbers[i] = int(input())

index = 0
for e in expression:
    if 'A' <= e <= 'Z':
        if e not in alphabets:
            alphabets[e] = numbers[index]
            index += 1
               
stack = []

for e in expression:

    if 'A'<=e<='Z':
        stack.append(alphabets[e])
    else:
        top = stack[-1]

        if e == '+':
            if top == '-':
                stack.pop()
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2-n1
                stack.append(new_n)
                stack.append(e)
        
            elif e == '/' or e=='*':
                stack.append(e)

            else:
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 + n1
                stack.append(new_n)

        elif e == '-':
            if top == '+':
                stack.pop()
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 + n1
                stack.append(new_n)
                stack.append(e)
            
            elif e=='/' or e=='*':
                stack.append(e)
            
            else:
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 - n1
                stack.append(new_n)

        elif e == '*':
            if top == '+' or top =='-':
                stack.append(e)
            elif top == '/':
                stack.pop()
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 / n1
                stack.append(new_n)
                stack.append(e)
            else:
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 * n1
                stack.append(new_n)

        else:
            if top == '+' or top =='-':
                stack.append(e)
            elif top == '*':
                stack.pop()
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 * n1
                stack.append(new_n)
                stack.append(e)
            else:
                n1 = stack.pop()
                n2 = stack.pop()
                new_n = n2 / n1
                stack.append(new_n)

if type(stack[0]) == int:
    print("{:.2f}".format(float(stack[0])))

else:
    print("{:.2f}".format(stack[0]))

'''
문자면 스택에 넣고,
연산자면
1) 현재 처리 중인 연산자가 스택 상위 연산자보다 우선순위가 낮다면 스택에서 빼고, 현재 연산자 넣기
2) 현재 처리 중인 연산자가 스택 상위 연산자보다 우선순위가 높다면 현재 처리 중인 연산자를 넣음
3) 두 개가 같다면 안에 있는 것을 빼고, 현재를 넣음 
'''