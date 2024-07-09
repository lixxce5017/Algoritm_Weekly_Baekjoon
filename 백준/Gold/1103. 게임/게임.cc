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
//dfs로 판별해야하는 이유 안붙어 있을 수도 있음 애들이 
//그럼갱신되지 않고 INT_MAX 를 -1로 출력
using namespace std;
int n, m;
int arr[51][51];
bool visitied[51][51];
int dp[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dfs(int x, int y)
{
	if (dp[x][y])
		return dp[x][y];

	visitied[x][y] = true;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x+dx[i] * arr[x][y];
		int ny = y+dy[i] * arr[x][y];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m &&arr[nx][ny]!=0)
		{
			if (visitied[nx][ny] == true)
			{
				cout << -1;
				exit(0);
			}
			ret = max(ret, dfs(nx, ny));
		}
	
	}
	visitied[x][y] = false;
	return dp[x][y]=ret+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'H')
			{
				arr[i][j] = 0;
			}
			else
				arr[i][j] = s[j]-'0';
		}
	}
	cout << dfs(0, 0);
}