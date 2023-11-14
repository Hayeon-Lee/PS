def solution(brown, yellow):
    answer = []
    for i in range(1, yellow + 1, 1):
        if yellow % i == 0:
            height = i
            width = yellow // i
            
            total = ((2*width) + (2*height) + 4)
            if total == brown:
                answer.append(width + 2)
                answer.append(height + 2)
                break
    return answer
    
'''
약수 묶음을 구함
가로 세로를 구함
brown의 개수와 같아지면 리턴
'''