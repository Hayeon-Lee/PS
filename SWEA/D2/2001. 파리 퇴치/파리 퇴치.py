T = int(input())

for t in range(T):
    n, m = map(int, input().split())
    graph = []

    for i in range(n):
        tmp = list(map(int, input().split()))
        graph.append(tmp)
    
    answer = 0

    for i in range(n-m+1):
        for j in range(n-m+1):
            tmp_answer = 0
            for q in range(i, i+m):
                for k in range(j, j+m):
                    tmp_answer += graph[q][k]
            answer = max(answer, tmp_answer)

    print(f"#{t+1} {answer}")