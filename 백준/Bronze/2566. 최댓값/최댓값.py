import sys
input = sys.stdin.readline

x = 0
y = 0
maximum = 0

for i in range(9):
    tmp_arr = list(map(int, input().split()))
    
    for j in range(9):
        if tmp_arr[j] >= maximum:
            maximum = tmp_arr[j]
            x = i
            y = j

print(maximum)
print(x+1, y+1)
