#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int arr[100003];
#include <climits>
pair<long, long>ans;
int main(void) {


	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	long long start = 1;
	long long end = n;
	long long sum2 = INT_MAX;
	while (start < end)
	{
		if (abs(arr[start]+arr[end]) < abs(sum2))
		{
			ans.first = arr[start];
			ans.second = arr[end];
			sum2 = arr[start] + arr[end];
		}
		 if (abs(arr[start]) > abs(arr[end]))
		{
			 start++;			
		}
		else
		{
			 end--;
		}
	}
	if (ans.first > ans.second)
	{
		cout << ans.second << " " << ans.first;
	}
	else
	{
		cout << ans.first << " " << ans.second;
	}
}

