import heapq

frame = int(input())
good = int(input())
student = list(map(int, input().split()))

s_dict = {}
for s in student:
    if s not in s_dict:
        if len(s_dict) >= frame:
            tmp = heapq.nsmallest(min(s_dict), s_dict, key=s_dict.get)
            s_dict.pop(tmp[0])

        s_dict[s] = 1
    else:
        s_dict[s] += 1

answer = sorted(s_dict.keys())
print(*answer)