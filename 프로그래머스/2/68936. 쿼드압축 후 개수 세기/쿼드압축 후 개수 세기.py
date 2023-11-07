def compress(w, h, l, answer, arr):
    value = arr[w][h]
    for i in range(w, w+l):
        for j in range(h, h+l):
            if arr[i][j] != value:
                l = l//2
                compress(w,h,l,answer,arr)
                compress(w,h+l,l,answer,arr)
                compress(w+l,h,l,answer,arr)
                compress(w+l,h+l,l,answer,arr)
                return
    answer[value] += 1
                

def solution(arr):
    length = len(arr)
    answer = [0, 0]
    compress(0, 0, length, answer, arr)
    
    return answer

