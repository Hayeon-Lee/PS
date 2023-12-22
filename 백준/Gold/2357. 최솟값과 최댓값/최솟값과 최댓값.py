import sys  
from math import *  
input = sys.stdin.readline  

# 세그먼트 트리 초기화  
def init_min(now, left, right):  
    if left == right:  
        tree_min[now] = nums[left]  
        return tree_min[now]  
    mid = (left + right) // 2  
    tree_min[now] = min(init_min(now*2, left, mid), init_min(now*2+1, mid+1, right))  
    return tree_min[now]  

def init_max(now, left, right):  
    if left == right:  
        tree_max[now] = nums[left]  
        return tree_max[now]  
    mid = (left + right) // 2  
    tree_max[now] = max(init_max(now*2, left, mid), init_max(now*2+1, mid+1, right))  
    return tree_max[now]  

def query_min(now, start, end, left, right):  
    if start > right or end < left:  
        return 1000000001  
    if left <= start and end <= right:  
        return tree_min[now]  
    mid = (start+end) // 2  
    return min(query_min(now*2, start, mid, left, right), query_min(now*2+1, mid+1, end, left, right))  

def query_max(now, start, end, left, right):  
    if start > right or end < left:  
        return 0  
    if left <= start and end <= right:  
        return tree_max[now]  
    mid = (start+end) // 2  
    return max(query_max(now*2, start, mid, left, right), query_max(now*2+1, mid+1, end, left, right))  


N, M = map(int, input().split())  
nums = []  

# 세그먼트 트리 사이즈 계산하기  
H = int(ceil(log(N, 2)))  
seg_size = 1 << (H+1)  
tree_min = [0] * seg_size  
tree_max = [0] * seg_size  

for _ in range(N):  
    nums.append(int(input()))  

init_min(1, 0, N-1)  
init_max(1, 0, N-1)  


for _ in range(M):  
    a, b = map(int, input().split())  
    print(query_min(1, 0, N-1, a-1, b-1), query_max(1, 0, N-1, a-1, b-1))