def recr(x,y,d):
    global ans
    #print(x,y)
    if arr[x][y]==0:
        ans+=1
        arr[x][y]=2
    nd=d
    for i in range(4):
        nd=(nd+3)%4
        nx=x+dx[nd]
        ny=y+dy[nd]
        if  nx>=0 and ny>=0 and nx<n and ny<m and arr[nx][ny]==0:
                recr(nx,ny,nd)
                return
    
    x=x-dx[d]
    y=y-dy[d]
    if arr[x][y]!=1:
        recr(x,y,d)

        return


ans=0
n,m= map(int,input().split())
sx,sy,d= map(int,input().split())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
#북동남서
dx= [-1,0,1,0]
dy= [0,1,0,-1]


recr(sx,sy,d)

print(ans)
