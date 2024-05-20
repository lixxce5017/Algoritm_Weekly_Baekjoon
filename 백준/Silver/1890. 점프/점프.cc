#include <iostream>
#include <algorithm>
#include <vector>
#include<stdio.h>
#include<deque>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;
int n;
int arr[101][101];
long long dp[101][101];

long long dfs(int x, int y)
{
  // cout << x << " " << y << " " << arr[x][y] << "\n";

    if (x == n-1 && y ==n-1)
    {
        return 1;
    }
    int now = arr[x][y];
    if (dp[x][y] == -1)
    {
        dp[x][y] = 0;
        if (x + now < n)
        {
            dp[x][y]+=dfs(x + now, y);
        }
        if (y + now < n)
        {
            dp[x][y]+=dfs(x, y + now);
        }
    }
      return dp[x][y];
}
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
  
    cout << dfs(0, 0);
}


