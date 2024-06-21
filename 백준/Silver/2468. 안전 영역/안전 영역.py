from collections import deque

dx=[0,0,-1,1]
dy=[1,-1,0,0]

def bfs(i,j,k):
    #global visitied
    queue=deque()
    queue.append((i,j))
    visitied[i][j]=1
    ans=0
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            if nx>=0 and ny>=0 and nx<n and ny<n:
                if visitied[nx][ny] == 0 and arr[nx][ny] > k:
                    queue.append((nx,ny))
                    visitied[nx][ny]= visitied[x][y]+1


n=int(input())
arr=[]

for i in range(n):
    arr.append(list(map(int,input().split())))
# 주의 높이 0부터 돌려야함
heght=0
for i in range(n):
    heght=max(arr[i])
res=0
for k in range(0,heght+1):
    cnt=0
    visitied=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if arr[i][j]>k and visitied[i][j]==0:
                cnt+=1
                bfs(i,j,k)
    #print(cnt)
    res=max(cnt,res)
print(res)
