n, k = map(int, input().split())
dp = [0 for i in range(31)]
dp[0] = 1	# 0! = 1이므로 dp[0] = 1을 저장
for i in range(1, 31):
    dp[i] = i * dp[i-1]
#이렇게 간단하게 되는거였다고,.,.?
print(dp[n-1] // (dp[n-k] * dp[k-1]))