
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
vector<int> v;
vector<int>tmp;
struct Q
{
	int idx, s, e;
};
vector<Q> q;
vector<pair<int,int>> ans;
int cnt[1010101];
int max_cnt[1010101];
int rn;

// max_cnt[cnt[v[ri]]]의 의미
//v[ri]의 숫자가 몇번 cnt 돼서 그 cnt 수와 동일한게 몇개있는지
//ex 5라는 숫자는 3번 나왔고 동일하게 3번 나온 숫자들은 1개이다
bool cmp(Q a, Q b)
{
	if (a.s/rn != b.s/rn)
	{
		return a.s / rn < b.s / rn;
	}
	else
	{
		return a.e < b.e;
	}
}
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n>>m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	tmp = v;
	sort(tmp.begin() + 1, tmp.end());
	tmp.erase(unique(tmp.begin() + 1, tmp.end()), tmp.end());
	for (int i = 1; i <= n; i++) {
		v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push_back({ i,a,b });
	}
	rn = sqrt(n);
	sort(q.begin(), q.end(),cmp);
	int li = 2;
	int ri = 1;
	int sum = 0;
	int res = 0;

	for (int i = 0; i < q.size(); i++)
	{
		int s = q[i].s;
		int e = q[i].e;
		int idx = q[i].idx;
		while (s < li)
		{
			li--;
			if (cnt[v[li]])
			{
				max_cnt[cnt[v[li]]]--;
			}
			cnt[v[li]]++;
			max_cnt[cnt[v[li]]]++;
			res = max(res, cnt[v[li]]);

		}
		while (s > li)
		{
			max_cnt[cnt[v[li]]]--;
			//max_cnt[cnt[v[li]]] 존재 의의 여기서 만약 제일 많이 카운트된
			//3이 카운트가 0이라면 전체 값에서 빼야함 만약
			//2 1이 있어서 2가 1로 줄어 값이 있다면
			// 2 2 1 1에서 2 2만 존재하는 거기 때문에 빼면안됨
			if (cnt[v[li]] == res && !max_cnt[cnt[v[li]]])
				res--;
			cnt[v[li]]--;
			max_cnt[cnt[v[li]]]++;
			li++;
		}
		while (e > ri)
		{
			//더하기
			ri++;
			if (cnt[v[ri]])
				max_cnt[cnt[v[ri]]]--;
			cnt[v[ri]]++;
			max_cnt[cnt[v[ri]]]++;
			res = max(res, cnt[v[ri]]);
		}
		while (e < ri)
		{
			max_cnt[cnt[v[ri]]]--;
			if (cnt[v[ri]] == res && !max_cnt[cnt[v[ri]]])
				res--;
			cnt[v[ri]]--;
			max_cnt[cnt[v[ri]]]++;
			ri--;
			//빼기
		}

		ans.push_back({ idx,res });
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].second << "\n";
	}
}