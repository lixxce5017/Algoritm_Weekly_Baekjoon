import collections
import heapq
n,k=map(int,input().split())
Map=[list(map(int,input().split()))for _ in range(n)]
que=collections.deque()
virs=[]
visitied = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if Map[i][j]!=0:
            virs.append((Map[i][j],i,j))
virs.sort()
for val,x,y in virs:
    que.append((val,x,y,1))
time,ex,ey=map(int,input().split())

def bfs(q,w):

    visitied[q][w]=1
    dx=[0,0,-1,1]
    dy=[1,-1,0,0]
    res=0
    while que:
        val,x,y,t=que.popleft()
        if t >= time:
            return

        for i in range(4):
            nx= dx[i]+x
            ny=dy[i]+y
            if nx<0 or ny<0 or nx>=n or ny>=n:
                continue
            if visitied[nx][ny]!=0 or Map[nx][ny]!=0:
                continue
            que.append((val,nx,ny,t))
            visitied[nx][ny]=visitied[x][y]+1
            Map[nx][ny]=val

bfs(0,0)
if Map[ex - 1][ey - 1] == 0:
    print(0)
else:
    print(Map[ex - 1][ey - 1])