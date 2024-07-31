# 2번 방법

"""이 문제를 풀 때는 산봉우리의 의미를 잘 파악하는 것이 중요하다. 문제에서 정의한 산봉우리는 "
같은 높이를 가지는 하나의 격자 혹은 인접한 격자들의 집합으로 이루어져 있다
8방향에서 같은 높이를 가진 산등성이면 재귀적으로 가고 그룹보다 큰 애가 있으면 산봉우리가 아니라고 판단
"""




def dfs(x,y):
    global cnt
    global falg
    visitied[x][y]=True
    for i in range(8):
        nx=dx[i]+x
        ny=dy[i]+y
        if nx>=0 and ny>=0 and nx<n and ny<m:
            if Map[nx][ny]>Map[x][y]:
                falg=False
            if visitied[nx][ny]==False and Map[nx][ny]==Map[x][y]:
                dfs(nx,ny)



dx=[-1,-1,0,1,1,1,0,-1]
dy=[0,1,1,1,0,-1,-1,-1]
n,m=map(int,input().split())
Map=[list(map(int,input().split())) for _ in range(n)]
ans=0
visitied=[[False]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        if not visitied[i][j]:
            falg=True
            dfs(i,j)
            if falg:
                ans+=1
print(ans)
