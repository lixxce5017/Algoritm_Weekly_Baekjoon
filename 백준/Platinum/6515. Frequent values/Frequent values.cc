#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <cstring>
using namespace std;
int n;
vector<int> v;
vector<int>tmp_v;
struct Q
{
	int idx, s, e;
};
vector<Q> q;
vector<pair<int, int>> ans;
int cnt[202020];
int max_cnt[101010];
int rn;

// max_cnt[cnt[v[ri]]]의 의미
//v[ri]의 숫자가 몇번 cnt 돼서 그 cnt 수와 동일한게 몇개있는지
//ex 5라는 숫자는 3번 나왔고 동일하게 3번 나온 숫자들은 1개이다
bool cmp(Q a, Q b)
{
	if (a.s / rn != b.s / rn)
	{
		return a.s / rn < b.s / rn;
	}
	else
	{
		return a.e < b.e;
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (1)
	{
		int m;
		cin >> m;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			v[i] = tmp + 100000;
		}

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			q.push_back({ i,a,b });
		}
		rn = sqrt(n);
		sort(q.begin(), q.end(), cmp);
		int li = 2;
		int ri = 1;
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int s = q[i].s;
			int e = q[i].e;
			int idx = q[i].idx;

			while (s < li)
			{
				//포함
				li--;
				if (cnt[v[li]])
				{
					max_cnt[cnt[v[li]]]--;
				}
				cnt[v[li]]++;
				max_cnt[cnt[v[li]]]++;
				sum = max(sum, cnt[v[li]]);
			}
			while (s > li)
			{
				max_cnt[cnt[v[li]]]--;
				//a!=0
				//!a
				if (sum == cnt[v[li]] && !max_cnt[cnt[v[li]]])
				{
					sum--;
				}
				cnt[v[li]]--;
				max_cnt[cnt[v[li]]]++;
				li++;
			}
			while (e < ri)
			{
				max_cnt[cnt[v[ri]]]--;
				if (sum == cnt[v[ri]] && !max_cnt[cnt[v[ri]]])
				{
					sum--;
				}
				cnt[v[ri]]--;
				max_cnt[cnt[v[ri]]]++;
				ri--;

			}
			while (e > ri)
			{
				//포함
				ri++;
				if (cnt[v[ri]])
				{
					max_cnt[cnt[v[ri]]]--;
				}
				cnt[v[ri]]++;
				max_cnt[cnt[v[ri]]]++;
				sum = max(sum, cnt[v[ri]]);
			}
			ans.push_back({ idx,sum });
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < m; i++)
		{
			cout << ans[i].second << "\n";
		}
		rn = 0;
		v.clear();
		ans.clear();
		q.clear();
		memset(cnt, 0, sizeof(cnt));
		memset(max_cnt, 0, sizeof(max_cnt));
		cin >> n;
		if (n == 0)
			return 0;
	}
}