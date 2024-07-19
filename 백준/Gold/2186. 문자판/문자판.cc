#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<tuple>

using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[103][103];
int dp[103][103][81];
string s;
int k = 0;
int n, m;
int dfs(int x, int y,int depth)
{
	//cout << depth << " ";
	if (depth == s.size() - 1)
	{
		return 1;
	}
	if (dp[x][y][depth] != -1)
	{
		return dp[x][y][depth];
	}
	dp[x][y][depth] = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int nx = x + (dx[i] * j);
			int ny = y + (dy[i] * j);
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
		
			if (arr[nx][ny] == s[depth+1])
			{
				//cout << nx << " " << ny << "\n";
				dp[x][y][depth] += dfs(nx, ny, depth + 1);
			}
		}
	}
	return dp[x][y][depth];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m>>k;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j]==s[0])
				ret += dfs(i, j, 0);
		}
	}
	cout << ret;

}