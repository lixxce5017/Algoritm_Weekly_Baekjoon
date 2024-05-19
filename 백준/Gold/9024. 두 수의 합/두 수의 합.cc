#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define maxxx 100000
typedef long long ll;
long long ans = INT_MAX;
pair<int, int>ans2;
int arr[1000003];
//정수 k에 합이 가깝다는 것은 두수의 합의 차이가 최소인 갯수를 찾아야 하는것
//포인터를 움직이는 방식은 절대값을 취하지 않은 합이
//k보다 크냐 작냐로 결정\

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t)
	{
		int n;
		int k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		sort(arr + 1, arr + n + 1);
		int start = 1;
		int end = n;
		int cnt = 0;
		while (start < end)
		{
			//먼저 조건 검사 두 수의 합을 더하고 k-로 뺀 차가 현재의 ans와 같다면?
			if (abs(k - (arr[start] + arr[end])) == ans)
			{
				cnt++;
			}
			//다음 조건 두 수의 차가 더 적다면 cnt는 1 또 ans로 갱신
			else if (ans > abs(k - (arr[start] + arr[end])))
			{
				ans = abs(k -(arr[start] + arr[end]));
				cnt = 1;
			}
			if (arr[start] + arr[end] == k)
			{
				start++;
				end--;
			}
			else if (arr[start] + arr[end] > k)
			{
				end--;
			}
			else
			{
				start++;
			}
		}
		ans = INT_MAX;
		t--;
		cout << cnt << "\n";
	}
}