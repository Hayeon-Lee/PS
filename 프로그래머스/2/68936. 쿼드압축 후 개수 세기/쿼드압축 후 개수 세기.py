def compress(w, h, l,arr):
    value = arr[w][h]
    for i in range(w, w+l):
        for j in range(h, h+l):
            if arr[i][j] != value:
                l = l//2
                compress(w,h,l,arr)
                compress(w,h+l,l,arr)
                compress(w+l,h,l,arr)
                compress(w+l,h+l,l,arr)
                return
    answer[value] += 1
                

def solution(arr):
    global answer
    length = len(arr)
    answer = [0, 0]
    
    compress(0, 0, length, arr)
    
    return answer

