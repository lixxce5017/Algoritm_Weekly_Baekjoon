#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int arr[1003][1003];
int res = 0;
int val = 0;
int prumingMax = 0;
bool visitied[1003][1003];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int cnt, int idx)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << x << " " << y << " " << cnt << " " << idx << "\n";
	//가지치기
	//현재 남은 idx에 최댓값 다 곱하고 현재 값 더한게
	//지금까지 갱신된 맥스보다 작다면 
	//더 이상 가능성이 없으므로 return
	if (cnt + (4 - idx) * prumingMax < res)
		return;
	if (idx == 4)
	{
		val = max(cnt, val);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		//네모 모양에서 인접된 애들이 한번씩 더 카운트 됨
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visitied[nx][ny] == false)
			{
				if (idx == 2)
				{
					visitied[nx][ny] = true;
					dfs(x, y, cnt + arr[nx][ny], idx + 1);
					visitied[nx][ny] = false;
				}

				visitied[nx][ny] = true;
				dfs(nx, ny, cnt + arr[nx][ny], idx + 1);
				visitied[nx][ny] = false;
			}

		}
	}
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			//가지치기
			prumingMax = max(arr[i][j], prumingMax);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			val = 0;
			visitied[i][j] = true;
			dfs(i, j, arr[i][j], 1);
			visitied[i][j] = false;
			res = max(val, res);
		}
	}
	
	cout << res;

}
