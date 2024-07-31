# 2번 방법
import sys
sys.setrecursionlimit(100000)
"""에게 싸움을 걸 수 있고 영역 안의 양의 수가 늑대의 수보다 많다면 이기고,
 늑대를 우리에서 쫓아낸다. 그렇지 않다면 늑대가 그 지역 안의 모든 양을 먹는다.
 조건문 주의"""




def dfs(x,y):
    global cnt_sheep
    global  cnt_wolf
    visitied[x][y]=True
    for i in range(4):
        nx=dx[i]+x
        ny=dy[i]+y

        if nx <0 or ny<0 or nx>=n or ny>=m:
            continue
        if visitied[nx][ny] or Map[nx][ny]=='#':
            continue
        if Map[nx][ny]=='v':
            cnt_wolf+=1
        elif Map[nx][ny]=='o':
            cnt_sheep+=1
        dfs(nx,ny)



dx=[0,0,-1,1]
dy=[1,-1,0,0]
n,m=map(int,input().split())
Map=[list(input().rstrip()) for _ in range(n)]
ans=0
visitied=[[False]*m for _ in range(n)]

ans_sheep=0
ans_wolf = 0
for i in range(n):
    for j in range(m):
        if not visitied[i][j]:
            cnt_sheep=0
            cnt_wolf=0
            dfs(i,j)
            if cnt_wolf<cnt_sheep:
                ans_sheep+=cnt_sheep
            else:
                ans_wolf+=cnt_wolf

print(ans_sheep,ans_wolf,sep=' ')
