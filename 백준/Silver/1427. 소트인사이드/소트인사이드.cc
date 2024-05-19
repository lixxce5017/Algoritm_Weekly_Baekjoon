#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int arr[10];
int main()
{
	int n;
	int cnt = 0;
	cin >> n;

	while (n !=0)
	{
		arr[cnt] = n % 10;
		cnt++;
		n /=10;
	}
	sort(arr, arr + cnt, greater<int>());
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i];
	}
}