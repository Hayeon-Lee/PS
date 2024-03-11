import sys
input = sys.stdin.readline

n = int(input())
students = list(map(int, input().split()))
b, c = map(int, input().split())

answer = 0

for s in students:
    if s <= b: #총감독관은 한 명
        answer += 1
        continue

    tmp_s = s-b #총감독관이 볼 수 있는 학생 제외
    answer += 1

    answer += (tmp_s // c)
    if tmp_s%c != 0:
        answer += 1

print(answer)
    
