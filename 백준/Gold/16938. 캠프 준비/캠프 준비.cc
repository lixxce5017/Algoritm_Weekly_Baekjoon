#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
#include<queue>
int visitied[16];
int n, l, r, x;
int ans = 0;
int arr[16];
int maxx = 0;
//순열
int cnt = 0;
void dfs(int cnt,int idx)
{
	if (cnt >= 2)
	{
		int sum = 0;
		int minn = 9999999;
		int maxx = 0;
		for (int i = 0; i < n; i++)
		{
			if (visitied[i] == true)
			{
				sum += arr[i];
				minn = min(arr[i], minn);
				maxx = max(arr[i], maxx);
				//visitied[i] = false;
			}
		}//cout << sum << " " << maxx << " " << minn << "\n";
		if (sum >= l && sum <= r)
		{
			
			int res = maxx - minn;
			//cout << sum << " " << maxx << " " << minn << " " << res << "\n";
			if (res >= x)
			{
				ans++;
			}
		}
		
	}
	for (int i = idx; i < n; i++)
	{
		if (visitied[i] == false)
		{
			visitied[i] = true;
			dfs(cnt + 1, i + 1);
			visitied[i] = false;
		}
	}

	
}
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dfs(0, 0);
	cout << ans;
}