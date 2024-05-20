#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
pair<int, int> arr[300001];
int val[300001];
priority_queue <int>myq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	
	for (int i = 0; i < n; i++)
	{
		
		cin >> arr[i].first >> arr[i].second;

		//앞이 무게
		//뒤가 가격
	}
	//1. 보석 가격을 기준으로 정렬을 해준다.
	//2. 가방은 오름차순 정렬을 시행해준다.
	//3. 가격이 높은 보석을 차례대로 보석 무게와 비슷한 가방을 찾아서 넣어준다(보석 가격 누적계산)

	
	for (int i = 0; i < k; i++)
	{
		cin >> val[i];

	}
	sort(arr, arr + n);
	sort(val, val + k);
	int dx = 0;
	ll res = 0;
	for (int i = 0; i < k; i++)
	{
		while (dx < n && arr[dx].first <= val[i])
		{
			myq.push(arr[dx].second);
			dx++;
		}
		if (!myq.empty())
		{
			res += myq.top();
			myq.pop();
		}
	}
	
	
	cout << res;
}


