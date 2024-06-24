#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int arr[100003];
int main()
{
	int n, m;
	int maxx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	maxx = arr[n-1];
	for (int i = n-1; i >= 0; i--)
	{
		//단순하게 최대중량으로 비교가 들어감
		//어차피 최대중량에서 작은걸로 비교가 들어가니 곱하기가 맞음
		int cur = arr[i] * (n - i);
		//cout << cur << " ";
		if (maxx< cur)
		{
			maxx = cur;
		}
	}
	cout << maxx;
}