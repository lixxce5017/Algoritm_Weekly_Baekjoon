from collections import deque
import copy
import sys
dx=[0,0,-1,1]
dy=[1,-1,0,0]
def bfs():
    myq=deque()
    visitied = [[0] * (n) for _ in range(n)]
    map=arr
    for i in range(virsu_cnt):
        if virsu_chk[i] ==1:
            myq.append(virus[i])
            visitied[virus[i][0]][virus[i][1]] =1
            map[virus[i][0]][virus[i][1]]=-2
        else:
            map[virus[i][0]][virus[i][1]]=-1


    while myq:
        x,y=myq.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx>=n or ny>=n or nx<0 or ny<0:
                continue
            if visitied[nx][ny]!=0:
                continue
            #바이러스 활성화
            if (map[nx][ny]==-1 or map[nx][ny]==0) and visitied[nx][ny]==0:
                visitied[nx][ny] = visitied[x][y]+1
                myq.append((nx, ny))

    temp_ans=0

    for i in range(n):
        for j in range(n):
            if visitied[i][j] == 0 and map[i][j] == 0:
                return 9999999
            elif map[i][j]==-1:
                continue
            elif map[i][j]!=-2 or map[i][j]!=-1 or map[i][j]!=1:
                temp_ans=max(visitied[i][j]-1,temp_ans)

    return temp_ans
def dfs(depth,idx):
    global res
    if depth==m:
        res=min(res,bfs())
        return

    for i in range(idx,virsu_cnt):
        if virsu_chk[i]==0:
            virsu_chk[i]=1
            dfs(depth+1,i+1)
            virsu_chk[i]=0

n,m= map(int, sys.stdin.readline().split())
arr=[]
virus=[]
res=9999999
visitied = [[0] * (n) for _ in range(n)]
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

virsu_cnt=0
for i in range(n):
    for j in range(n):
        if arr[i][j]==2:
            virus.append((i,j))
            virsu_cnt+=1
virsu_chk=[0]*virsu_cnt
dfs(0,0)
if res==9999999:
    print(-1)
else:
    print(res)
""" 
5 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 2 0 2 0
1 1 1 1 1
answer:2
5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
2 1 1 1 1
2 2 2 2 0
answer : 1
바이러스가 켜진다는 말이 애매하다
즉 그전 바이러스도 값을 들고 가지만
최댓값 갱신할때는 뻬줘야한다.
"""