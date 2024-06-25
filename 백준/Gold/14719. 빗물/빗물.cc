#include <algorithm>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
int arr[503];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		int maxx = 0;
		int maxx2 = 0;
		for (int j = i + 1; j < m; j++)
		{
			maxx = max(arr[j], maxx);
		}
		for (int j = i - 1; j >= 0; j--)
		{
			maxx2 = max(arr[j], maxx2);
		}
		res += max(0, min(maxx, maxx2) - arr[i]);
	}
	cout << res;
}