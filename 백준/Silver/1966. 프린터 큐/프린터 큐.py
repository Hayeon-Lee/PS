import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    documents = deque(list(map(int, input().split())))
    indexes = deque([i for i in range(N)])

    answer = 0
    while True:
        max_priority = max(documents)

        if documents[0] != max_priority:
            tmp = documents.popleft()
            documents.append(tmp)

            tmp = indexes.popleft()
            indexes.append(tmp)
        
        else:
            if indexes[0] == M:
                answer += 1
                print(answer)
                break

            else:
                documents.popleft()
                indexes.popleft()
                answer += 1

    