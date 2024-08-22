n,m=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
na=[]

for i in range(n-1):
    na.append(arr[i+1]-arr[i])

na.sort()
ans=0
for i in range(n-m):
    ans+=na[i]

print(ans)