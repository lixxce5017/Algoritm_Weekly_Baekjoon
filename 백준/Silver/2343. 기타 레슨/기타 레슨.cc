#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<climits>
using namespace std;
int arr[100003];
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	long long end = 0;
	long long start =0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		end += arr[i];
		if (arr[i] > start)
		{
			start = arr[i];
		}
	}

	long long result = 0;
	while (start <=end)
	{
		long long mid = (start + end) / 2;
		long long cnt = 0;
		long long sum = 0;
	
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] + sum > mid)
			{
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		cnt++;

		if (cnt >m)
		{
			start = mid + 1;
		}
		else if(cnt<=m)
		{
			end = mid - 1;
			result = mid;
		}
	}
	cout << result;

	return 0;
}


