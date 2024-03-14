from collections import deque

gear = {
    1: deque(list(map(int, input().strip()))),
    2: deque(list(map(int, input().strip()))),
    3: deque(list(map(int, input().strip()))),
    4: deque(list(map(int, input().strip())))
}

rotate_info = []
for _ in range(int(input())):
    which, direction = map(int, input().split())
    rotate_info.append((which, direction))

#회전시키기
def rotate(w, d):
    global gear

    if d == 1:
        tmp = gear[w].pop()
        gear[w].appendleft(tmp)
    
    if d == -1:
        tmp = gear[w].popleft()
        gear[w].append(tmp)

#첫 번째 톱니 확인
def check_one():
    global turn_list

    # 두 번째 톱니의 6번과 맞물림 
    if turn_list[2] == 0 and gear[1][2] != gear[2][6]:
        turn_list[2] = turn_list[1]*(-1)
        check_two()

def check_two():
    global turn_list

    if turn_list[1] == 0 and gear[1][2] != gear[2][6]:
        turn_list[1] = turn_list[2]*(-1)
        check_one()
    
    if turn_list[3] == 0 and gear[2][2] != gear[3][6]:
        turn_list[3] = turn_list[2]*(-1)
        check_three()

def check_three():
    global turn_list

    if turn_list[2] == 0 and gear[2][2] != gear[3][6]:
        turn_list[2] = turn_list[3]*(-1)
        check_two()
    
    if turn_list[4] == 0 and gear[3][2] != gear[4][6]:
        turn_list[4] = turn_list[3]*(-1)
        check_four()

def check_four():
    global turn_list

    if turn_list[3] == 0 and gear[3][2] != gear[4][6]:
        turn_list[3] = turn_list[4]*-1
        check_three()

turn_list = [0, 0, 0, 0, 0]
for r in rotate_info:
    which, direction = r
    turn_list = [0] * 5

    if which == 1:
        turn_list[1] = direction
        check_one()

    elif which == 2:
        turn_list[2] = direction
        check_two()

    elif which == 3:
        turn_list[3] = direction
        check_three()

    else:
        turn_list[4] = direction
        check_four()

    for i in range(1, 5):
        if turn_list[i]!=0:
            rotate(i, turn_list[i])

answer = 0
for key, value in gear.items():
    if key == 1 and gear[key][0] == 1:
        answer += 1
    
    if key == 2 and gear[key][0] == 1:
        answer += 2

    if key==3 and gear[key][0] == 1:
        answer += 4

    if key==4 and gear[key][0] == 1:
        answer += 8

print(answer)


'''
첫 번째 톱니바퀴: 2
두 번째 톱니바퀴: 6, 2
세 번째 톱니바퀴: 6, 2
네 번째 톱니바퀴: 6

1번은 시계방향: 맨 뒤를 빼서 앞에 넣는다, 이후 첫 번째 원소가 12시방향.
-1은 반시계방향: 맨 앞을 빼서 뒤로 넣는다, 이후 첫 번째 원소가 12시방향.

돌리기 전에 같으면 안 돌고
다르면 돌고 
'''