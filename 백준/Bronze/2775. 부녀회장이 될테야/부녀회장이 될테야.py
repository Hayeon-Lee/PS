import sys
input = sys.stdin.readline

apartment = [[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14]]

for i in range(0, 14):
    tmp_arr = [0, 1]
    for j in range(2, 15, 1):
        value = tmp_arr[j-1] + apartment[i][j]
        tmp_arr.append(value)
    apartment.append(tmp_arr)

T = int(input())
for i in range(T):
    k = int(input())
    n = int(input())
    print(apartment[k][n])

