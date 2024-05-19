#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define maxxx 100000
typedef long long ll;
long long ans = INT_MAX;
pair<int,int>ans2;
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
			ans2.first = arr[start];
			ans2.second = arr[end];
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
	if (ans2.first > ans2.second)
	{
		cout << ans2.second << " " << ans2.first;
	}
	else
	{
		cout << ans2.first << " " << ans2.second;
	}
}