from collections import deque

n,m= map(int,input().split())
arr=[]
for i in range(n):
    arr.append(list(input()))
dx= [0,1,0,-1]
dy = [1,0,-1,0]


def bfs(i,j):
    queue= deque()
    queue.append((i,j))
    visitied = [[0] * m for _ in range(n)]
    visitied[i][j]=1
    ans=0
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx>=0 and ny>=0 and nx<n and ny<m :
                if visitied[nx][ny]==0 and arr[nx][ny]=="L":
                    visitied[nx][ny]= visitied[x][y]+1
                    ans= max(ans,visitied[x][y])
                    queue.append((nx,ny))
    return ans

res =0


for i in range(n):
    for j in range(m):
        if arr[i][j] == "L":
            res=max(res,bfs(i,j))
    if res == int(i) +int(j) - 2:
        break
print(res)