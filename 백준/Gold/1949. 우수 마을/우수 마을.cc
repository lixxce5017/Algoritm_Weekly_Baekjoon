
#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;
bool visitied[10003] = { 0, };
vector<vector<int>>Arr;
int dp[10003][2] = {0,};
void dfs(int n)
{
    visitied[n] = true;
    dp[n][0] = 0;
    for (auto i : Arr[n])
    {
        if (visitied[i] == false)
        {
            dfs(i);
            //내가 우수 다음이 일반
            dp[n][1] = dp[i][0] + dp[n][1];
            //내가 일반이고 남이 
            dp[n][0] += max(dp[i][0], dp[i][1]);
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
   

    cin >> n;
    Arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][1];
    }
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        Arr[a].push_back(b);
        Arr[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][1], dp[1][0]);

   
    return 0;
}