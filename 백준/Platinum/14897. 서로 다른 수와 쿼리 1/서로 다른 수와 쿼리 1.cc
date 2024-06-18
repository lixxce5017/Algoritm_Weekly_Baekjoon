
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
int rn;
bool cmp(Q a, Q b)
{
	//sort의 내부적 로직이 궁금 쳐도 안나옴
	//당연히 제곱근으로 섹션 나눴을때 작은 구간 섹션애들이 앞으로 정렬
	//근데 왜 <형태가 오름차순 >형태가 내림차순일까

	if (a.s/rn != b.s/rn)
	{
		// 예상 a.s가5, b.s4가 왔으면 
		return a.s / rn < b.s / rn;
		//return false하고 바꾸지 않음
	}
	else
	{
		return a.e < b.e;
	}
}
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	tmp = v;
	sort(tmp.begin() + 1, tmp.end());
	//새로배운 좌표압축
	// unique는 유니크하게 남기고 그 뒷부분은 원래 배열원소가 남는다
	//이레이즈로 그부분부터 지워나가는것
	tmp.erase(unique(tmp.begin() + 1, tmp.end()), tmp.end());
	//결국 그 친구들이 있는 최초 번지수로 값을 넣어줌으로써 좌표압축이 성립됨
	for (int i = 1; i <= n; i++) {
		v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push_back({ i,a,b });
	}
	//기본적으로 오름차순 
	//우선순위 큐가 기본 내림차순
	rn = sqrt(n);
	sort(q.begin(), q.end(),cmp);

	int li = 2;
	int ri = 1;
	int sum = 0;
	//cout << "d";
	//cout << q[0].s << " "<<q[0].e << "\n";
	for (int i = 0; i < q.size(); i++)
	{
		//cout << i << " ";
		int s = q[i].s;
		int e = q[i].e;
		int idx = q[i].idx;
		while (s < li)
		{
			//cout << li << " ";
			li--;
			cnt[v[li]]++;
			if (cnt[v[li]] == 1)
				sum++;
		}
		while (s > li)
		{
			cnt[v[li]]--;
			if (cnt[v[li]] == 0)
				sum--;
			li++;
		}
		while (e > ri)
		{
		
			//더하기
			ri++;
			cnt[v[ri]]++;
			if (cnt[v[ri]] == 1)
				sum++;
		}
		while (e < ri)
		{
			cnt[v[ri]]--;
			if (cnt[v[ri]] ==0)
				sum--;
			ri--;
			//빼기
		}

		ans.push_back({ idx,sum });
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].second << "\n";
	}
}