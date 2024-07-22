import sys
m=int(sys.stdin.readline())
dp=[0]*  10000001
for i in range(10000001):
    dp[i]= i
ans=[]
for i in range(2,10000001):
    if dp[i]!=0:
        ans.append(i)
        for k in range(i*2,10000001,i):
            dp[k]=0
print(ans[m-1])