#include <iostream>
#include <string>
#include<math.h>
#include<cstring>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

//1부터 9까지
int dp[1003][1003];
int main() {
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> dp[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (dp[i][j] != 0)
                {
                    dp[i][j] = min({ dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j] }) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans<<"\n";
        memset(dp, 0, sizeof(dp));
    }

    
}