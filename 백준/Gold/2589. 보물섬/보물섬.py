import collections
n,m=map(int,input().split())
Map=[list(input().rstrip())for _ in range(n)]


def bfs(q,w):
    visitied=[[0]*m for _ in range(n)]
    que=collections.deque()
    que.append((q,w))
    visitied[q][w]=1
    dx=[0,0,-1,1]
    dy=[1,-1,0,0]
    res=0
    while que:
        x,y=que.popleft()
        for i in range(4):
            nx= dx[i]+x
            ny=dy[i]+y
            if nx<0 or ny<0 or nx>=n or ny>=m:
                continue
            if visitied[nx][ny]!=0 or Map[nx][ny]=='W':
                continue
            que.append((nx,ny))
            visitied[nx][ny]=visitied[x][y]+1
            res=max(res,visitied[nx][ny])
    return res

ans=0
for i in range(n):
    for j in range(m):
        if Map[i][j]=='L':
            q=bfs(i,j)
            ans=max(ans,q)

print(ans-1)
