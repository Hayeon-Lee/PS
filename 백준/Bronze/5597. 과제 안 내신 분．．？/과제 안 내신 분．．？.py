students = [0 for _ in range(30)]

for i in range(28):
    number = int(input())
    students[number-1] = 1

for i in range(30):
    if students[i] != 1:
        print(i+1)