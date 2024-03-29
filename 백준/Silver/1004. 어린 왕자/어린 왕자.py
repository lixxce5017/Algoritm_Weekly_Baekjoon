
t=int(input())
while t:
    sx,sy,dx,dy= map(int,input().split())
    n=int(input())
    cnt=0
    space=[]
    for i in range(n):
        cx,cy,r= map(int,input().split())
        space.append((cx,cy,r))
    
    for x,y,R in space:
        R=R**2
        dist1=abs(sx-x)**2+abs(sy-y)**2
        dist2=abs(dx-x)**2+abs(dy-y)**2
        if dist1<R and dist2<R:
            continue
        elif dist1<R:
            cnt+=1
        elif dist2 < R:
            cnt += 1
    
    print(cnt)

    t-=1

