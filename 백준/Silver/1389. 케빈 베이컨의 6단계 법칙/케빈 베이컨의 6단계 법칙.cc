#include<vector>
#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;
static int arr[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 10000001;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[k][j] + arr[i][k]);
			}
		}
	}
	int answer = 0;
	int min = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
		{
			tmp += arr[i][j];
		}
		if (min > tmp)
		{
			min = tmp;
			answer = i;
		}

	}
	cout << answer;

}