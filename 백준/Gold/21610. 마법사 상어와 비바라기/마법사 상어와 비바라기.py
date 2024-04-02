n,m= map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]

dis=[]
for i in range(m):
    a,b= map(int,input().split())
    dis.append((a,b))

coluds=[(n-1,0),(n-1,1),(n-2,0),(n-2,1)]
dx8=("empty",0,-1,-1,-1,0,1,1,1)
dy8=("empty",-1,-1,0,1,1,1,0,-1)
dist=[(-1,-1),(-1,1),(1,1),(1,-1)]
cloud=[]
for d,s in dis:
    cloud.clear()
    for x,y in coluds:
        nx=(x+dx8[d]*s)%n
        ny=(y+dy8[d]*s)%n
        arr[nx][ny]+=1
        cloud.append((nx,ny))

    for cx,cy in cloud:
        for dx,dy in dist:
            rx=cx+dx
            ry=cy+dy
            if n > rx >= 0 and n > ry >= 0:
                if arr[rx][ry]>0:
                    arr[cx][cy]+=1

    newMap=[]
    for i in range(n):
        for j in range(n):
            if arr[i][j]<2 or (i,j) in cloud:
                continue
            else:
                newMap.append((i, j))
                arr[i][j] = arr[i][j] - 2

    coluds=newMap

cnt = 0
for i in range(n):
    for j in range(n):
        cnt+=arr[i][j]

print(cnt)