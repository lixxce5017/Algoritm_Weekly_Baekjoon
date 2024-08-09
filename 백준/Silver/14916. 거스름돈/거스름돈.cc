#include <iostream>
#include <string>
#include<math.h>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;

int dp[100010];

int main() {


    int n;
    cin >> n;
  
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 1; i <= 100004; i++)
    {
        dp[i] = 987654321;
    }
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for (int i = 6; i <= n; i++)
    {
            dp[i] =dp[i - 2] + 1;
            dp[i] = min(dp[i], dp[i - 5] + 1);
 
 
    }
    if (dp[n] == 987654321)
        cout << -1;
    else
    cout << dp[n];

    return 0;
}