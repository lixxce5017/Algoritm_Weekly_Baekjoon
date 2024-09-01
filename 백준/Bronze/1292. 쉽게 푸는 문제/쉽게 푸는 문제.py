n,m=map(int,input().split())
arr=[-1]
cnt=1
NumCnt=1
for i in range(1001):
    arr.append(NumCnt)
    if NumCnt==cnt:
        NumCnt+=1
        cnt=1
    else:
        cnt+=1
ans=0
for i in range(n,m+1):
    ans+=arr[i]
print(ans)