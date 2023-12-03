from collections import Counter

def solution(n, results):
    
    board = [[0 for _ in range(n)] for _ in range(n)]
    
    for winner, loser in results:
        board[winner-1][loser-1] = 1
        board[loser-1][winner-1] = -1
    
    # b가 a에게 지면, b는 a를 이긴 모두에게 짐 
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if board[i][j] == 0: #아직 모름
                    #i-j 에 대한 매치 정보가 없음 
                    #i가 k를 이기고, k가 j를 이기면 i는 j를 이긴 것
                    if board[i][k] == 1 and board[k][j] == 1:
                        board[i][j] = 1
                    #i가 k에게 지고, k가 j에게 지면 i는 j에게 진다
                    elif board[i][k] == -1 and board[k][j] == -1:
                        board[i][j] = -1
    
    answer = 0
    
    for i in board:
        count = Counter(i)[0]
        if count == 1:
            answer += 1
    
    return answer
            