from collections import deque
import sys

input=sys.stdin.readline
R,C=map(int,input().split())
arr=[list(input().strip()) for _ in range(R)]

dx=[1,-1,0,0]
dy=[0,0,1,-1]

def escape():
    queue=deque()
    for i in range(R):
        for j in range(C):
            if arr[i][j]=='D':   
                D=[i,j]                
            elif arr[i][j]=='*':    
                queue.append([i,j,'*'])
            elif arr[i][j]=='S':
                arr[i][j]==1
                S=[i,j,0]       
    queue.append(S)            
  
    while queue:
        x,y,z=queue.popleft()
        if x==D[0] and y==D[1]:
            print(z)
            break
        else:
            for i in range(4):  
                nx=x+dx[i]
                ny=y+dy[i]
                if z=='*' and 0<=nx<R and 0<=ny<C and arr[nx][ny]!='X' and arr[nx][ny]!='D' and arr[nx][ny]!='*':
                    arr[nx][ny]='*'
                    queue.append([nx,ny,'*'])
                elif type(z)==int and 0<=nx<R and 0<=ny<C and (arr[nx][ny]=='.' or arr[nx][ny]=='D'):
                    arr[nx][ny]=z+1
                    queue.append([nx,ny,z+1])
        if len(queue)==0:
            print('KAKTUS')
            break     

escape()