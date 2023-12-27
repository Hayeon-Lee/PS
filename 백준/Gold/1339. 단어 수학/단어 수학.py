import sys
input = sys.stdin.readline

N = int(input())
words = []
alphabets = {}
numbers = {}

for _ in range(N): words.append(input().strip())

#자리수별 가중치 부여
for w in words:
    for i in range(len(w)):
        score = 10 ** (len(w) - i - 1)
        if w[i] in alphabets : alphabets[w[i]] += score
        else : alphabets[w[i]] = score

#가중치별 내림차순 정렬
alphabets = dict(sorted(alphabets.items(), key=lambda x:x[1], reverse=True))

#글자에게 숫자 할당
score = 9
for key in alphabets:
    numbers[key] = score
    score-=1

#숫자로 변환
answer = 0
for w in words:
    new_str = ''
    for c in w:
        new_str+=str(numbers[c])
    answer+=int(new_str)

print(answer)

'''
맨 앞자리 글자는 무조건 큰 숫자
숫자 길이가 제일 길면서, 그 중 가장 앞자리 숫자에게 9부터 할당
-> 문제: 첫번째로 확인한 요소에게 큰 수가 무조건 가버림

자릿수별로 가중치를 부여하자

'''