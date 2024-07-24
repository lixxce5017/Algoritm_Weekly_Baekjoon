from copy import deepcopy
import sys
import collections
arr=[0]*14
def check(i):
    for j in range(i):
        if arr[j]==arr[i] or abs(arr[j]-arr[i]) == abs(j-i):
            return False
    return True

def dfs(i):
    global ans
    if i==n:
        ans+=1
        return

    for j in range(n):
        arr[i]=j
        if check(i)==True:
            dfs(i+1)
        arr[i]=0


input=sys.stdin.readline
n=int(input())
ans=0
dfs(0)
print(ans)