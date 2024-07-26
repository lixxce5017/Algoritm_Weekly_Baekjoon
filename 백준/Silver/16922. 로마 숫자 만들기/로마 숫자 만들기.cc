#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int n;
bool visitied[5];
bool chek[1000000];
int lorma[5] = { 1,5,10,50 };
int cnt = 0;
//중복 조합 문제, 중복 순열이라 착각했음
// 중복 조합은 i+1로 가면 안됨
// 아마, II, IV, IX, IL, VI, VV, VX, VL, XI, XV, XX, XL, LI, LV, LX, LL 이렇게 나올 것이다.
//중복 조합 중복을 허용한 조합

//순서가 상관 없이 -> 조합
//순서에 상관 있게 뽑기 순열->
// 순서에 상관 있고 중복을 허용 ->중복순열
// 순서가 상관 없고 중복을 허용 -> 중복 조합
void dfs(int level, int sum,int idx)
{
	if (level == n)
	{
		if (chek[sum] == false)
		{
			chek[sum] = true;
			cnt++;
		}
		return;
	}
	for (int i = idx; i < 4; i++)
	{
		dfs(level + 1, lorma[i] + sum,i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dfs(0, 0,0);
	cout << cnt;
}