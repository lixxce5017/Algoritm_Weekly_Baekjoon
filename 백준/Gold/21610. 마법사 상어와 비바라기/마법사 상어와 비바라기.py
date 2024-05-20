import sys
n,m= map(int,input().split())
Map=[]
for _ in range(n):
     tmp=list(map(int,(input().split())))
     Map.append(tmp)
dx8=("empty",0,-1,-1,-1,0,1,1,1)
dy8=("empty",-1,-1,0,1,1,1,0,-1)
qurey=[]
dist=[(-1,-1),(-1,1),(1,1),(1,-1)]
for _ in range(m):
    a,b=map(int,input().split())
    qurey.append((a,b))
# d번 방향으로 s칸 이동
coluds=[(n-1,0),(n-1,1),(n-2,0),(n-2,1)]
for d,s in qurey:
    cloud = []
    for x,y in coluds:
        nx=(x+dx8[d]*s)%n
        ny=(y+dy8[d]*s)%n
        nx=nx
        ny=ny
        Map[nx][ny]+=1
        cloud.append((nx,ny))

    for cx,cy in cloud:
        for dx,dy in dist:
            nx=dx+cx
            ny=dy+cy
            if nx>=0 and ny >=0 and nx<n and ny<n:
                if Map[nx][ny]!=0:
                    Map[cx][cy]+=1
    cnt=0
    newMap=[]
    for i in range(n):
        for j in range(n):
                if Map[i][j]<2 or (i,j) in cloud :
                    continue
                newMap.append((i,j))
                Map[i][j]=Map[i][j]-2

    coluds=newMap

for i in range(n):
    for j in range(n):
        cnt+=Map[i][j]

print(cnt)
