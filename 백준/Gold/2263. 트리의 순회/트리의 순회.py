import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
preorder = []

indexes = [0 for _ in range(n+1)]
for i in range(n):
    indexes[inorder[i]] = i

def find_preorder(i_s, i_e, p_s, p_e): #0, n-1, 0, n-1
    global preorder
    
    if i_e < i_s or p_e < p_s:
        return
    
    root = postorder[p_e] 
    print(root, end = ' ')

    left = indexes[root] - i_s #왼쪽 트리의 노드 개수
    right = i_e - indexes[root] #오른쪽 트리의 노드 개수

    find_preorder(i_s, i_s + left - 1 , p_s, (p_s + left - 1))
    find_preorder(i_e - right + 1 , i_e, (p_e - right), (p_e - 1))

find_preorder(0, n-1, 0, n - 1)


'''
프리오더: 루 왼 오

인오더: 왼 루 오 -> 루트 기준으로 나눠보자
포스트오더의 맨 마지막이 루트노드임
루트 기준으로 왼쪽 처음, 왼쪽 끝, 오른쪽 처음, 오른쪽 끝

포스트오더: 왼 오 루 -> 맨 마지막이 루트임

시간초과 -> 노드 위치를 배열로 만들어서 저장
'''