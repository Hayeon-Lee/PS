import sys
input = sys.stdin.readline

n = int(input())
muscles = list(map(int, input().split()))

muscles.sort()
answer = 0

if len(muscles) == 1:
    answer = muscles[0]

elif len(muscles) == 2:
    answer = muscles[0] + muscles[1]

else:
    couple_muscles = []
    if len(muscles)%2==0:
        for i in range(n):
            tmp = (muscles[i] + muscles[n-1-i])
            couple_muscles.append(tmp)
        answer = max(couple_muscles)    
    
    else:
        last = muscles[-1]
        for i in range(n-1):
            tmp = (muscles[i] + muscles[n-2-i])
            couple_muscles.append(tmp)
        answer = max(couple_muscles)
        answer = max(answer, last)

print(answer)