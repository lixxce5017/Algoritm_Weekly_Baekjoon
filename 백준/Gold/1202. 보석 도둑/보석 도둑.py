import heapq
n,k=map(int,input().split())
hq=[]
napsake=[]
juarle=[]
for i in range(n):
    a,b=map(int,input().split())
    juarle.append((a,b))

for i in range(k):
    a=int(input())
    napsake.append(a)
juarle.sort()
napsake.sort()

idx=0
ans=0
for i in range(k):

    while idx<n and juarle[idx][0]<=napsake[i]:
        heapq.heappush(hq,-juarle[idx][1])
        idx+=1
    if len(hq)!=0:
        ans+=hq[0]*-1
        heapq.heappop(hq)

print(ans)
