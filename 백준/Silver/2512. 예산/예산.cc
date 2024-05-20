#include<iostream>/
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<climits>
using namespace std;
int arr[1000003] = { 0, };
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	long long maxx = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		maxx += arr[i];
		if (res<  arr[i])
		{
			res = arr[i];
		}
	}
	cin >> m;
	long long start = 0;
	while (start <= maxx)
	{
		long long mid = (start + maxx) / 2;
		long long cnt = 0;
		bool falg = true;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] > mid)
			{
				falg = false;
				cnt += arr[i]-(arr[i] - mid);
			}
			else
			{
				cnt += arr[i];
			}
		}

		if (cnt <= m)
		{
			if (falg == false)
			{
				res = mid;
			}
			start = mid + 1;
		}
		else
		{
			maxx = mid - 1;
		}
	}

	cout << res;
}
