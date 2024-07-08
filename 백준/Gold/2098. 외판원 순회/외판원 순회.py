import sys
INF=1e+9
n=int(input())
arr=[]
dp=[[None]*(1<<n) for _ in range(n)]
for i in range(n):
    q= list(map(int,input().split()))
    arr.append(q)
#print(1<<n)


def dfs(node,chk):
    #print(chk)
    if chk==(1<<n)-1:
        if arr[node][0]!=0:
            return arr[node][0]
        else:
            return INF
    if dp[node][chk]!=None:
        return dp[node][chk]
    min_v=INF
    for i in range(1, n):
        if (arr[node][i]!=0 and (chk &(1<<i))==0):
            min_v=min(min_v,dfs(i,chk|(1<<i))+arr[node][i])
    dp[node][chk]=min_v
    return dp[node][chk]




print(dfs(0,1))

