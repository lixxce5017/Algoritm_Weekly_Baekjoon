#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include<queue>
using namespace std;
int arr[51][51] = { 0, };
bool visitied[51][51] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m, t;
void bfs(int x, int y)
{
	
	queue<pair<int,int>>myq;
	myq.push(make_pair(x, y));
	while (!myq.empty())
	{
		int nx = myq.front().first;
		int ny = myq.front().second;

		myq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = nx + dx[i];
			int nexty = ny + dy[i];
			if (arr[nextx][nexty] > 0 && nextx < n && nexty < m && nextx >= 0 && nexty >= 0)
			{
				if (visitied[nextx][nexty] == false)
				{
					myq.push(make_pair(nextx, nexty));
					visitied[nextx][nexty] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	cin >> num;
	while (num)
	{
		int cnt = 0;

		cin >> n >> m >> t;
		for (int i = 0; i < t; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visitied[i][j] == false)
				{
					bfs(i, j);
					
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		num--;
		fill(&arr[0][0], &arr[50][50], 0);
		fill(&visitied[0][0], &visitied[50][50], false);
	}
	return 0;
}