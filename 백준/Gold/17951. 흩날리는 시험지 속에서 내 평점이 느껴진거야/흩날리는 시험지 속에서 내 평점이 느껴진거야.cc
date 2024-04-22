#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
int arr[100003];
#include <climits>
int main(void) {


	int n,k;
	cin >> n >> k;
	long long end = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		end += arr[i];
	}
	int start = 0;
	long long res = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long t = 0;
		long long cnt =0;
		for (int i = 0; i < n; i++)
		{
			t += arr[i];
			if (t>= mid)
			{
				cnt++;
				t = 0;
			}
		}
		//cout << mid << " ";
		if (cnt >= k)
		{
			res = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;

		}
	}
	cout << res;
	


}
