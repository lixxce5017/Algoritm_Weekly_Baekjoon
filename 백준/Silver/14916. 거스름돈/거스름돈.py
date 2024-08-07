n = int(input())
dp=[-1]*(n+10)
dp[2]=1
dp[5]=1
#작은 수부터 조건문 봐야함
#안그러면 4같은 친구들은 이미 -1로 초기화 되어 있는데
# 2라는 값을  min하면 갱신이 안됨
for i in range(3,n+1):
    if dp[i-2]!=-1:
        dp[i]=dp[i-2]+1
    if dp[i-5]!=-1 and i>5:
        dp[i]=min(dp[i-5]+1,dp[i])

print(dp[n])