          
import copy
#맵 백업시 깊은 복사 얕은 복사 조심           
def dfs(num):
    global res
    global lis
    if num==len(cctv_site):
        tmp=0
        for i in range(n):
            for j in range(m):
                if lis[i][j]==0:
                     tmp+=1
        res=min(res,tmp)
        return
    backup_Map=[[0]*m for _ in range(m)]             
    cctv=cctv_site[num]
    cctv_x=cctv[0]
    cctv_y=cctv[1]
    cctv_num=cctv[2]
    #0이 북 1이 동 2가 남 3이 서
    for i in range(cctv_rote[cctv_num]):
        backup_Map=copy.deepcopy(lis)
        if cctv_num==0:
            detection(i,cctv_x,cctv_y)
        elif cctv_num ==1:
            detection(i+2,cctv_x,cctv_y)
            detection(i,cctv_x,cctv_y)
        elif cctv_num==2:
            detection(i,cctv_x,cctv_y)
            detection(i+1,cctv_x,cctv_y)
        elif cctv_num==3:
            detection(i,cctv_x,cctv_y)
            detection(i+1,cctv_x,cctv_y)
            detection(i+2,cctv_x,cctv_y)
 
        elif cctv_num==4:
            detection(i,cctv_x,cctv_y)
            detection(i+1,cctv_x,cctv_y)
            detection(i+2,cctv_x,cctv_y)
            detection(i+3,cctv_x,cctv_y)
        dfs(num+1)
        lis=copy.deepcopy(backup_Map)
            
            
def detection(d,x,y):
    global backup_Map
    #0북 1동 2남  3서
    d=d%4
    if d==0:
        for nx in range(x-1,-1,-1):
            if lis[nx][y]==6:
                break
            lis[nx][y]=-1

    if d==1:
        for ny in range(y+1,m):
            if lis[x][ny]==6:
                break
            lis[x][ny]=-1
    if d==2:
        for nx in range(x+1,n):
            if lis[nx][y]==6:
                break
            lis[nx][y]=-1
    if d==3:
        for ny in range(y-1,-1,-1):
            if lis[x][ny]==6:
                break
            lis[x][ny]=-1  

n,m=map(int,input().split())

lis=[]
#cctv 돌아가는 회전수
cctv_rote=[4,2,4,4,1]
cctv_site=[]
res=9999
for i in range(n):
    lis.append(list(map(int,input().split())))

for i in range(n):
    for j in range(m):
        if lis[i][j]!=0 and lis[i][j]!=6:
            #cctv의 x,y,번호
            cctv_site.append((i,j,lis[i][j]-1))             

dfs(0)
print(res)