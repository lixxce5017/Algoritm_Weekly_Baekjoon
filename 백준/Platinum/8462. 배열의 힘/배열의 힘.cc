#include <cstdio>
#include <iostream>
#include <vector>
#include<tuple>
#include<cmath>
#include <algorithm>
using namespace std;
int arr[100003];
int maxx = 0;
long long ans[100003];
long long  cnt[1000003];
long long sum = 0;
int max_cnt[100003];
typedef struct {
	int l, r;
	int idx;
}Q;
vector<Q>q;
int RN;
//모스 알고리즘 이용 l에서 루트 n 나눈게 더 큰걸로 리턴 or 같으면 r이 뒤에나오는걸로 리턴
//서로 다른 개수를 새는 방법은 카운터 배열을 만들어서 새로 가는 부분이 1일때만 카운트를 세는
//방식


//1안 매번 초기화 해주면 10만 곱하기 10만 시간초과
//수쿼 6 좀 만 응용하면됨 쉬움
//비슷한 문제 배열의 힘 수열과 쿼리 5,백설공주와 난쟁이 연습하기 mos 연습하기 좋음
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

void add(int a) {
	sum -= cnt[arr[a]] * cnt[arr[a]] * arr[a];
	cnt[arr[a]]++;
	sum += cnt[arr[a]] * cnt[arr[a]] * arr[a];
}
void sub(int a) {
	sum -= cnt[arr[a]] * cnt[arr[a]] * arr[a];
	cnt[arr[a]]--;
	sum += cnt[arr[a]] * cnt[arr[a]] * arr[a];
}
int main() {
	int qi;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	int n;

	cin >> n>>m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push_back({ a-1, b-1, i });
	}
	RN = sqrt(n);
	sort(q.begin(), q.end(), cmp);

	int lp = 2, rp = 1;
	for (int i = 0; i < m; i++)
	{
		//cout << i << " ";
		int l = q[i].l, r = q[i].r;
		int idx = q[i].idx;

		while (l < lp) {
			//cnt[arr[--lp]]++;
			add(--lp);
		}
		while (l > lp) {
			//cnt[arr[lp++]]--;
			sub(lp++);
		}
		while (rp < r) {
			//cnt[arr[++rp]]++;
			add(++rp);
		}
		while (rp > r) {
			//cnt[arr[rp--]]--;
			sub(rp--);
		}
		ans[idx] = sum;
	}
	for (int i = 0; i < m; i++)
	{
		cout << ans[i]<<"\n";

	}
	return 0;
}