T = int(input())

for i in range(T):
    inputs = list(map(int, input().split()))

    answer = 0
    for n in inputs:
        if n%2 != 0:
            answer += n
    
    print("#%d %d" %(i+1, answer))
