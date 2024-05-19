#include<iostream>/
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>k;

	int start = 0;
	int end = k;
	int ans;


	while (start <= end)
	{
		int mideel = (end + start) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(mideel / i, n);
		}
		if (cnt <k)
		{
			start = mideel + 1;
		}
		else
		{
			ans = mideel;
			end = mideel - 1;
		}
	}
	
	cout << ans;
	
}
