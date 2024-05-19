#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define maxxx 100000
typedef long long ll;
long long ans = INT_MAX;
long long ans2 = INT_MAX;
int arr[100003];
//0에 가깝다는것은 두 수를 계산한 절대값이 0에 가까운것
//즉 가장 작은 절대값이 답이 되게 됨
//포인터를 움직이는 방식은 절대값을 취하지 않은 합이
//0보다 크냐 작냐로 결정
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	int start = 1;
	int end = n;
	while (start < end)
	{
		//cout << start << " " << end<<"\n";
		if (abs(arr[start]+ arr[end]) < ans)
		{
			ans = abs(arr[start]+arr[end]);
			ans2 = arr[start] + arr[end];
			//cout << ans<<" ";
		}
		if (arr[start]+arr[end]>0)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	cout << ans2;
}