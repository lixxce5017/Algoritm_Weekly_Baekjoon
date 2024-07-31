# 2번 방법
import sys
sys.setrecursionlimit(100000000)




def dfs(x,y):
    visitied[x][y]=True
    global ans
    for i in range(4):
        nx=dx[i]+x
        ny=dy[i]+y

        if nx <0 or ny<0 or nx>=n or ny>=m:
            continue
        if visitied[nx][ny] or Map[nx][ny]=='X':
            continue
        if Map[nx][ny]=='P':
            ans+=1
        dfs(nx,ny)



dx=[0,0,-1,1]
dy=[1,-1,0,0]
input=sys.stdin.readline
n,m=map(int,input().split())
Map=[list(input().rstrip()) for _ in range(n)]
ans=0
visitied=[[False]*m for _ in range(n)]

x=0
y = 0
for i in range(n):
    for j in range(m):
        if Map[i][j]=='I':
            x=i
            y=j
ans=0
dfs(x,y)
if ans:
    print(ans)
else:
    print("TT")


