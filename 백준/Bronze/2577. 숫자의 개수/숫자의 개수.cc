#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX 500004
int arr[11];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	long long ans = n * m * k;
	while (ans)
	{
		int tmep=ans % 10;
		arr[tmep]++;
		ans=ans / 10;
	}
	for (int i = 0; i <= 9; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}