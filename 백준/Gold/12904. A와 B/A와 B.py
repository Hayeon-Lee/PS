import sys
input = sys.stdin.readline

def make_str(target_str):
    
    global flag

    while target_str:
        if target_str[-1] == 'A':
            target_str.pop()
        elif target_str[-1] == 'B':
            target_str.pop()
            target_str.reverse()

        if target_str == S:
            flag = 1
            break


S = list(input().strip())
T = list(input().strip())
flag = 0

make_str(T)
print(flag)