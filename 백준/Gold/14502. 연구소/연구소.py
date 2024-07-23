from copy import deepcopy
import sys
import collections
input=sys.stdin.readline
def bfs():
    global n,m
    que=collections.deque()
    for i in virus:
        que.append((i[0],i[1]))
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]
    while que:
        x,y=que.pop()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx>=0 and ny>=0 and nx<n and ny<m:
                if Map[nx][ny]==0:
                    que.append((nx,ny))
                    Map[nx][ny]=2

def chek():
    cnt=0
    for i in range(n):
        for j in range(m):
            if Map[i][j]==0:
                cnt+=1

    return cnt

ans=0
n,m=map(int,input().split())
Map=[list(map(int,input().split())) for _ in range(n)]
copy_map=deepcopy(Map)
wall=[]
virus=[]
wall_cnt=0

for i in range(n):
    for j in range(m):
        if Map[i][j] == 0:
            wall.append((i, j))

        elif Map[i][j]==2:
            virus.append((i,j))

for i in range(len(wall)-2):
    for j in range(i+1,len(wall)-1):
        for k in range(j+1,len(wall)):
            wall2=[wall[i],wall[j],wall[k]]
            for x,y in wall2:
                Map[x][y]=1
            bfs()
            ans=max(ans,chek())
            Map=deepcopy(copy_map)

            for x, y in wall2:
                Map[x][y] = 0


print(ans)