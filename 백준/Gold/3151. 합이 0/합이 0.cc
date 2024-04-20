#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
long long arr[10003];
#include <climits>
long long ans[3];
int main(void) {


	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);
	long long cnt = 0;
	for (int i = 1; i <= n - 1; i++)
	{
	
		for (int j = i + 1; j <= n; j++)
		{
			long long sum2 = arr[i]+arr[j];
			int idx = upper_bound(arr + j + 1, arr + n+1, -sum2) -arr;
			int idx2 = lower_bound(arr + j + 1, arr + n+1, -sum2) - arr;
			cnt += idx2 - idx;
		}

	}
	cout << -1*cnt;
}
