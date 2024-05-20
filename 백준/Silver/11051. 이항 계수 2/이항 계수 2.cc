#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;
	
	
	for (int i = 0; i <= n; i++)
	{
		arr[i][i] = 1;
		arr[i][0] = 1;
		arr[i][1] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			arr[i][j] = arr[i][j] % 10007;
		}
	}
	cout << arr[n][k];
	return 0;
}