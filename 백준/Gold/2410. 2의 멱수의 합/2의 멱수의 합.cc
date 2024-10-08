#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>

using namespace std;
/*
N=1 -> 1

N=2 -> 1+1, 2

N=3 -> 1+1+1, 2+1

N=4 -> 1+1+1+1, 2+1+1, 2+2, 4

N=5 -> 1+1+1+1+1, 2+1+1+1, 2+2+1, 4+1

...



N이 홀수일 경우를 살펴보면, N-1의 가능한 조합 끝에 1씩을 더해주어 완성된다.

N=3 인 경우, N=2 일 때의 조합 (1+1, 2) 의 끝에 1씩을 더하여 (1+1+1, 2+1) 이 된다.

N=5 인 경우, N=4 일 때의 조합  (1+1+1+1, 2+1+1, 2+2, 4) 의 끝에 1씩을 더하여 (1+1+1+1+1, 2+1+1+1, 2+2+1, 4+1) 이 된다.



N이 짝수인 경우, N-1의 가능한 조합에 1을 더해준 것과 N/2의 가능한 조합에 2를 곱해준 값을 합쳐 완성된다.

N=4 인 경우, N=3 일 때의 조합 (1+1+1, 2+1) 의 끝에 1씩 더하여 (1+1+1+1, 2+1+1) 를 만들고, N=2 일 때의 조합 (1+1, 2) 에 2를 곱하여 (2+2, 4) 를 만든다. 이 둘을 합치면 (1+1+1+1, 2+1+1, 2+2, 4) 로, N=4 일 때의 가능한 조합이 된다.



즉, N이 홀수일 때 가능한 2의 멱수 조합 수는 N-1의 가능한 2의 멱수 조합 수와 같고,

N이 짝수 일 때 가능한 2의 멱수 조합 수는 N-1의 가능한 2의 멱수 조합 수와 N/2의 가능한 2의 멱수 조합 수를 더하여 구해진다.*/
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000001; i++)
	{
		if (i % 2 == 0)
			dp[i] = (dp[i / 2] + dp[i - 1]) % 1000000000;
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[n];
}