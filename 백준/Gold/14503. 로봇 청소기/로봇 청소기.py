from collections import deque

n,m=map(int,input().split())
sx,sy,d=map(int,input().split())
Map=[list(map(int,input().split()))for _ in range(n)]
visitied=[[0 for _ in range(m)] for _ in range(n)]
diretion=[(-1,0),(0,1),(1,0),(0,-1)]

cnt=1
queue=deque()
queue.append((sx,sy))
visitied[sx][sy]=1
while queue:
    x,y= queue.popleft()
    goga=0
    for dx,dy in diretion:
        d=(d+3)%4
        nx=x+diretion[d][0]
        ny=y+diretion[d][1]
        if 0<=nx<n and 0<=ny<m:
            if visitied[nx][ny]==0 and Map[nx][ny]==0:
                queue.append((nx,ny))
                visitied[nx][ny]=1
                cnt+=1
                goga=1
                break
    if goga == 0:
        if Map[x - diretion[d][0]][y - diretion[d][1]] == 0:
            queue.append((x - diretion[d][0], y - diretion[d][1]))
        else:
            print(cnt)
            break

