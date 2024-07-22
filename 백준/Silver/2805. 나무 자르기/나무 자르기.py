import sys
input = sys.stdin.readline

n,m=map(int,input().split())
arr=list(map(int,input().split()))
end=max(arr)
start=1
ans=0
while start<=end:
    mid=int((start+end)/2)
    cnt=0
    for i in arr:
        if i-mid>=0:
            cnt+=(i-mid)
    #print(start,end,cnt,mid)
    if cnt>=m:
        ans = mid
        start=mid+1
    else:
        end=mid-1

print(int(ans))