import sys
m = int(input())
dic = dict()
arr_1 = list(map(int, input().split()))

for item in arr_1:
  if item in dic:
    dic[item]+=1
  else:
    dic[item]=1

n = int(input())
arr_2 = list(map(int, input().split()))
for find in arr_2:
  if find in dic:
    sys.stdout.write("%d "%dic[find])
  else:
    sys.stdout.write("0 ")