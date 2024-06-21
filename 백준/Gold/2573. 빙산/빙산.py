from collections import deque

dx=[0,0,-1,1]
dy=[1,-1,0,0]

def bfs(i,j):
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
            if nx>=0 and ny>=0 and nx<n and ny<m:
                if visitied[nx][ny] == 0 and arr[nx][ny]!=0:
                    queue.append((nx,ny))
                    visitied[nx][ny]= visitied[x][y]+1
                elif arr[nx][ny]==0:
                    count[x][y]+=1


n,m=map(int,input().split())
arr=[]
visitied = [[0] * m for _ in range(n)]
count = [[0] * m for _ in range(n)]
for i in range(n):
    arr.append(list(map(int,input().split())))
year=0
while 1:
    visitied = [[0] * m for _ in range(n)]
    count=count = [[0] * m for _ in range(n)]
    land_cnt=0
    for i in range(n):
        for j in range(m):
            if visitied[i][j]==0 and arr[i][j]!=0:
                bfs(i,j)
                land_cnt+=1

    if land_cnt==0:
        print(0)
        break
    elif land_cnt>=2:
        print(year)
        break
    for i in range(n):
        for j in range(m):
            arr[i][j]-=count[i][j]
            if arr[i][j]<0:
                arr[i][j]=0

    year+=1

#4 4
#0 0 0 0
#0 3 1 0
#0 1 3 0
#0 0 0 0

#엣지 케이스
## 바로 배열에서 0 빼버리면 안빼야하는 값도 빼 버림
#필히 두개로 나눠서 관리 해야함