#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


int coin[11];
int main()
{
	int n, val, ans = 0;
	cin >> n >> val;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	//값이 큰 동전 단위 기준 정렬
	sort(coin, coin + n,greater<int>());
	for (int i = 0; i < n; i++)
	{
		//큰 동전부터 사용할 수 있는만큼 사용
		while (val - coin[i] >= 0)
		{
			ans++;
			val = val - coin[i];
		}

	}
	cout << ans;
}