#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
using namespace std;
int dx[3] = { 0,0,1};
int dy[3] = { 1,-1,0};
int n, m;
int arr[1001][1001];
long long dp[1001][1001][3];
bool visitied[1003][1003];
long long dfs(int x, int y,int idx)
{
	//cout << x << " "<<y<<"\n";
	if (x == n-1 && y == m-1)
	{
		return arr[n-1][m-1];
	}
	if (dp[x][y][idx] != -987654321)
	{
		return dp[x][y][idx];
	}
	visitied[x][y] = true;
	long long maxx = -987654321;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visitied[nx][ny]==false)
			maxx =  max(maxx,dfs(nx, ny,i));
		}
	
	}
	visitied[x][y] = false;
	dp[x][y][idx] = arr[x][y] +maxx;
	return dp[x][y][idx];



}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			dp[i][j][0] = -987654321;
			dp[i][j][1] = -987654321;
			dp[i][j][2] = -987654321;
		}
	}
	cout << dfs(0, 0, 0);;

}