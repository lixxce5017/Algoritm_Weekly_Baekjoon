#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include<stack>
#include<climits>

#define MAX 1000001
typedef long long ll;
using namespace std;
char val[503][503];
int dp[503][503];
int chk[503][503];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int cnt;
bool truth = false;
int dfs(int x, int y)
{

    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return 1;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    dp[x][y] = 0;

    int nx = x;
    int ny = y;

    if (val[x][y] == 'D')
    {
        nx += 1;
    }
    else if (val[x][y] == 'U')
    {
        nx -= 1;
    }
    else if (val[x][y] == 'L')
    {
        ny -= 1;
    }
    else if (val[x][y] == 'R')
    {
        ny += 1;
    }
    return dp[x][y] = dfs(nx, ny);
    

  
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n>>m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            val[i][j] = s[j];
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
               ans+=dfs(i, j);
        }
    }

    cout << ans << " ";
    //집합?
   

}