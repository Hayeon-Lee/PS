import sys
input = sys.stdin.readline

expressions = input().strip()
new_expressions = expressions.split('-')
answer = 0

if len(new_expressions) == 1: # - 기호가 없을 때
    tmp = new_expressions[0].split('+')
    for t in tmp:
        answer += int(t)
    
    print(answer)
    exit()

#answer를 시작값으로 초기화
if '+' in new_expressions[0]: 
    tmp = new_expressions[0].split('+')
    for t in tmp:
        answer += int(t)
    
else:
    answer = int(new_expressions[0])

#이후 연산
for new in new_expressions[1:]:
    if '+' in new :
        tmp = new.split('+')
        tmp_total = 0
        for t in tmp:
            tmp_total += int(t)
        answer -= tmp_total
    
    else:
        answer -= int(new)

print(answer)

