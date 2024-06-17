#include <cstdio>
#include <iostream>
#include <vector>
#include<tuple>
#include<cmath>
#include <algorithm>
using namespace std;
int arr[300003];
long long ans[1000003];
int cnt[200000];
typedef struct {
	int l, r;
	int idx;
}Q;
vector<Q>q;
int RN;
//모스 알고리즘 이용 l에서 루트 n 나눈게 더 큰걸로 리턴 or 같으면 r이 뒤에나오는걸로 리턴
//서로 다른 개수를 새는 방법은 카운터 배열을 만들어서 새로 가는 부분이 1일때만 카운트를 세는
//방식
bool cmp(Q a, Q b)
{
	if (a.l / RN != b.l / RN)
	{
		return a.l / RN < b.l / RN;
	}
	else
		return a.r < b.r;

}
int k;
int judge(int m)
{
	for (int i = 1; i <= k; i++)
	{
		//cout << cnt[i] << " ";
		if (cnt[i] >m/ 2)
		{
			return i;
		}
	}

	return -1;
}
int main() {
	int qi;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	int n;

	cin >> n>>k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push_back({ a-1, b-1, i });
	}
	RN = sqrt(n);
	sort(q.begin(), q.end(), cmp);

	int lp = 1, rp = 0;
	for (int i = 0; i < m; i++)
	{
		int l = q[i].l, r = q[i].r;
		int idx = q[i].idx;

		while (l < lp) {
			cnt[arr[--lp]]++;
		}
		while (l > lp) {
			cnt[arr[lp++]]--;
		}
		while (rp < r) {
			cnt[arr[++rp]]++;
		}
		while (rp > r) {
			cnt[arr[rp--]]--;
		}
		int sum = judge(r-l+1);
		ans[idx] = sum;
	}
	for (int i = 0; i < m; i++)
	{
		if (ans[i] == -1)
		{
			cout << "no" << "\n";
		}
		else
		{
			cout << "yes " << ans[i] << "\n";
		}
	}
	return 0;
}