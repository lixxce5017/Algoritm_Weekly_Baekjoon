t=int(input())
while t:
    # k층에 n호
    k = int(input())
    n = int(input())
    t-=1
    dp=[[0]*(n+1) for _ in range(k+1)]
    for i in range(1,n+1):
        dp[0][i]=i
    for i in range(1,k+1):
        for j in range(1,n+1):
            for q in range(1,j+1):
                dp[i][j]+=dp[i-1][q]

    print(dp[k][n])

