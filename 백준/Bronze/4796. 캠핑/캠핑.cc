#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
using namespace std;
int main()
{
	int cnt = 0;
	while (1)
	{
		//총 v일의 기간 중 p일 중 l 일동안만 캠핑장 이용 가능
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			return 0;
		cnt++;

		long long ans = 0;
		int temp = v / p;
		ans = temp * l;
		temp = v % p;
		if (temp < l)
			ans += temp;
		else
			ans += l;

		cout << "Case " << cnt << ": " << ans << "\n";
	}
}
