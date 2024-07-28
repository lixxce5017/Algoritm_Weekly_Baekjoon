import copy
from copy import deepcopy
from collections import  deque
import sys
#주의점 : 한쪽에서만 꽃이 폈는지 시간고려해서 봐줘야함
#반대쪽 큐에서는 이미 반대쪽에서 꽃처리가 되어버린 큐가 있다면 continue를 해줘야함
#조합이다. 배양액 배열을 만들어서 그것 기준으로 백트래킹을 가면된다.
# 다시 원복할때 배양액 맵은 다시 2가 되어야한다.
#큐가 둘 다 끝나야지 끝나야해서 or이고
# emtpy로 하면 둘 중 하나가 팝을 해버리기 때문 및 시간 때문에
# size로 가준다.
arr=[]
n,m,g,r=map(int,input().split())
for i in range(n):
    s=list(map(int,input().split()))
    arr.append(s)

injetion=[]
visitied=[[False] *m for _ in range(n)]
dx=[0,0,-1,1]
dy=[1,-1,0,0]
Map=copy.deepcopy(arr)
for i in range(n):
    for j in range(m):
        if arr[i][j]==2:
            injetion.append((i,j))

def rback(level,idx):
    if level==r:
        bfs()
        return
    for i in range(idx,len(injetion)):
        if not visitied[injetion[i][0]][injetion[i][1]]:
            visitied[injetion[i][0]][injetion[i][1]]=True
            Map[injetion[i][0]][injetion[i][1]]=5
            rback(level+1,i+1)
            Map[injetion[i][0]][injetion[i][1]] = 2
            visitied[injetion[i][0]][injetion[i][1]] = False

def gback(level,idx):
    if level==g:
        rback(0, 0)
        return
    for i in range(idx,len(injetion)):
        if not visitied[injetion[i][0]][injetion[i][1]]:
            visitied[injetion[i][0]][injetion[i][1]] = True
            Map[injetion[i][0]][injetion[i][1]] =6
            gback(level+1,i+1)
            Map[injetion[i][0]][injetion[i][1]] = 2
            visitied[injetion[i][0]][injetion[i][1]] = False




def bfs():
    global Map
    global dx
    global dy
    chk=[[0]*m for _ in range(n)]
    chk_g= [[0] * m for _ in range(n)]
    Map2=deepcopy(Map)
    req= deque()
    geq=deque()
    for i in range(n):
        for j in range(m):
            if Map[i][j]==5:
                req.append((i,j,1))
                chk_g[i][j]=1
            elif Map[i][j]==6:
                geq.append((i,j,1))
                chk[i][j]=1

    while req or geq:
        re_size=len(req)
        for k in range(re_size):
            rx,ry,time=req.popleft()
            if Map2[rx][ry] == 7:
                continue
            for i in range(4):
                nrx=rx+dx[i]
                nry=ry+dy[i]
                #6임
                if nrx<0 or nry<0 or nrx>=n or nry>=m:
                    continue
                if (Map2[nrx][nry]==1 or Map2[nrx][nry]==2)and chk[nrx][nry] == 0:
                    chk[nrx][nry] = time+1
                    Map2[nrx][nry] = 4
                    req.append((nrx, nry, time + 1))

        ge_size = len(geq)
        for k in range(ge_size):
            gx, gy, time = geq.popleft()

            for i in range(4):
                ngx = gx + dx[i]
                ngy = gy + dy[i]
                # 6임
                if ngx < 0 or ngy < 0 or ngx >= n or ngy >= m:
                    continue
                elif (Map2[ngx][ngy] == 1 or Map2[ngx][ngy] == 2) and chk_g[ngx][ngy] == 0:
                    chk_g[ngx][ngy] = time + 1
                    Map2[ngx][ngy] = 3
                    geq.append((ngx, ngy, time + 1))
                elif Map2[ngx][ngy] == 4 and chk_g[ngx][ngy] == 0:
                    if time + 1 == chk[ngx][ngy]:
                        chk_g[ngx][ngy] = time + 1
                        Map2[ngx][ngy] = 7




    t=0
    global ans
    for i in range(n):
        for j in range(m):
            if Map2[i][j]==7:
                t+=1
    ans=max(ans,t)

ans=0
gback(0,0)
print(ans)