#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[103];
	for (int i = 1; i <103; i++)
	{
		arr[i] = i;
	}
	int n,m;
	cin >> n >> m;
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		for (int i = 0; i <=(b -a) / 2; i++)
		{
			swap(arr[a + i], arr[b - i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << "\n";
	}
}


