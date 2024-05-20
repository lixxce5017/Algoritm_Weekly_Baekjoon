import sys
from itertools import permutations
import sys
sys.setrecursionlimit(10**7)

n= int(input())
arr= list(map(int,input().split()))
ans=0
ansArr=[]
visitied=[0] *n
def dfs (level):
    global ans
    if level==n:
        res=0
        for i in range(n-1):
            res+=abs(ansArr[i]-ansArr[i+1])
        ans=max(ans,res)
        return

    for i in range(n):
        if visitied[i]==0:
            visitied[i] = 1
            ansArr.append(arr[i])
            dfs(level+1)
            ansArr.pop()
            visitied[i]=0

dfs(0)
print(ans)