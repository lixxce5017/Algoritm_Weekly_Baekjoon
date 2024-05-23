
from collections import deque
n=int(input())
num=int(input())
arr=[[0]*(n+1)  for _ in range(n+1)]
for i in range(num):
    a,b=map(int,(input().split()))
    arr[a-1][b-1]=1
    
num2=int(input())
l=[]
for i in range(num2):
    a,b=input().split()
    a=int(a)
    l.append((a,b))


# 동 남 서 북
dx= [0,1,0,-1]
dy=[1,0,-1,0]
snak_len=0
deq=deque()
deq.append((0,0))
#첫번째는 동쪽
deretion=0
cnt=0
arr[0][0]=2
nx=0
ny=0
while 1:
    cnt+=1
    nx+=dx[deretion]
    ny+=dy[deretion]

    if nx<0 or ny<0 or nx>=n or ny>=n or arr[nx][ny]==2:
        break
    if arr[nx][ny]==1:
        arr[nx][ny]=2
        deq.appendleft((nx,ny))
    
    elif arr[nx][ny]==0:
        arr[nx][ny]=2
        deq.appendleft((nx,ny))
        q,w=deq.pop()
        arr[q][w]=0
    else:
       break

    for x,d in l:
        if cnt==x:
            if d == "D":
                deretion=(deretion+1)%4
            else:
                deretion = (deretion - 1) % 4


print(cnt)