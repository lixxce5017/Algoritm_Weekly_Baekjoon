import sys
m=int(sys.stdin.readline())
dp=[0]*100003
for i in range(100003):
    dp[i]= 1000100
coin=[0,1,2,5,7]
dp[0]=1
for i in range(1,5):
    for j in range(coin[i],m+1):
        dp[j]=min(dp[j],dp[j-coin[i]]+1)


print(dp[m]-1)