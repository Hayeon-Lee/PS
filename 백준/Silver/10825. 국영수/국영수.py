import sys
input = sys.stdin.readline

n = int(input())
students = []
for _ in range(n):
    name = list(map(str, input().strip().split(' ')))
    students.append(name)

students = sorted(students, key=lambda x:(-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for s in students:
    print(s[0])
