#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;


int arr[15003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);
	int cnt = 0;
	int start = 1;
	int end = n;

	while (start<end)
	{
		if (arr[start] + arr[end] == m)
		{
			cnt++;
			end--;
		}
		else if (arr[start] + arr[end] > m)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	cout << cnt;
}


