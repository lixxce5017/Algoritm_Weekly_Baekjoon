#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
1은 무조건 더해주는 것이 수를 크게 만든다.

0의 경우는 음수들을 다 묶고 남은 것이 있을 때 그 값을 더하게 되면 
결과값이 작아지므로 마지막으로 남은 음수값을 0과 곱한다.*/
priority_queue<int, vector<int>, greater<int>> miusq; //오름차순 음수
priority_queue<int> plusq;//내림차순 양수
int main() {
	
	int n;
	cin >> n;
	int zero = 0;
	int one = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a > 1)
		{
			plusq.push(a);
		}
		else if(a<0)
		{
			miusq.push(a);
		}
		else if (a == 1)
		{
			one++;
		}
		else if (a == 0)
		{
			zero++;
		}
	}
	long long ans = 0;
	while (plusq.size() > 1)
	{
		int temp1 = plusq.top();
		plusq.pop();
		int temp2 = plusq.top();
		plusq.pop();
		ans += temp1 * temp2;
	}
	if(!plusq.empty())
		ans += plusq.top();
		


	while (miusq.size() > 1)
	{
		int temp1 = miusq.top();
		miusq.pop();
		int temp2 = miusq.top();
		miusq.pop();
		ans += temp1 * temp2;
	}
	if (!miusq.empty())
	{
		if (zero==0)
		{
			ans += miusq.top();
			miusq.pop();
		}
	}
	cout << ans+one;
}
