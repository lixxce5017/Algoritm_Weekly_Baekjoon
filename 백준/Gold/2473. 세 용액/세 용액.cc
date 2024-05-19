#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
long long arr[5004];
#include <climits>
long long ans[3];
int main(void) {


	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	long long sum2 = LLONG_MAX;
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n - 2; i++)
	{
		int start = i + 1;
		int end = n;

		while (start < end)
		{
			long long val = arr[i] + arr[start] + arr[end];
			if (llabs(val) < sum2)
			{
				ans[0] = arr[i];
				ans[1] = arr[start];
				ans[2] = arr[end];
				sum2 = abs(arr[i] + arr[start] + arr[end]);

			}
		    if (val < 0)
			{

				start++;
			}
			else
			{
				end--;
			}

		}

	}
	sort(ans, ans + 3);
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}
