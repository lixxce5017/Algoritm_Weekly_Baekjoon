#include <iostream>
#include <string>
#include<math.h>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;

int dp[1500003];
int t[1500003];
int val[1500003];
int main() {


    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> val[i];
    }
    int time = n;
    int res = 0;
    for(int i=time;i>=0;i--)
    {
        dp[i] = dp[i + 1];
       if (i + t[i] <= time + 1)
        {
            dp[i] = max(dp[i +t[i]] + val[i], dp[i +1]);
        }
        res = max(res, dp[i]);
    }
    cout << res;
   
    return 0;
}