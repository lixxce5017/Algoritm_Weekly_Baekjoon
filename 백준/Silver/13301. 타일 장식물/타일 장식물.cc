#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include<unordered_map>
#include<map>
using namespace std;
//- 직사각형의 둘레는 (N번째 정사각형 한 변의 길이 + (N번째 정사각형 한 변의 길이+(N-1)번째 정사각형 한 변의 길이))
//* 2 임을 알 수 있다.
int n;
long long dp[10010];


int main() {
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] * 2 + (dp[n] + dp[n - 1]) * 2;
}


