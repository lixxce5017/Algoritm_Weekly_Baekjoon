#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<limits>
using namespace std;


long long arr[500003];
long long t[500003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i];
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= m; i++)
	{
		bool flag = true;
		int target = t[i];
		int start = 1;
		int end = n;
		while (start <= end)
		{
		
			int	mid = (start+end)/2;
			if (arr[mid] == target)
			{
				flag = false;
				t[i] = 1;
				break;
			}
			else if (arr[mid] > target)
			{//뒤로
				end = mid-1;
			}
			else
			{
				start = mid + 1;
			}
		}
		if (flag == true)
		{
			t[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << t[i]<<" ";
	}
}


