n=int(input())
arr=[]
idx=[]
for i in range(n):
    a=list(input().rstrip())
    arr.append(a)
    s_idx=[0]*(len(a))
    cnt=0
    cnt2=0
    
    for j,val in enumerate(a):
        falg=0
        for k in range(len(a)):
            if k==j:
                continue
            if a[k]==val and s_idx[k]!=0:
                s_idx[j]=s_idx[k]
                falg=1
                break
        if falg==0:
            cnt+=1
            s_idx[j]=cnt
    idx.append(s_idx)

ans=0
for i in range(len(arr)):
    for j in range(i+1,len(arr)):
        if idx[i]==idx[j]:
            ans+=1

print(ans)