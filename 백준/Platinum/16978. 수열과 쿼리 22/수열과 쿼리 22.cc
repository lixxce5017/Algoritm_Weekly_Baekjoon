#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
int arr[100004];
vector<pair<int,long long>>ans;
long long tree[400004];
typedef tuple<int, int, int,int > t;
queue<t> update;
vector<t> query;
typedef long long ll;
ll make_tree(int startidx, int endidx, int node) {
	if (startidx == endidx) return tree[node] = arr[startidx];
	int mid = (startidx + endidx) / 2;
	return tree[node] = make_tree(startidx, mid, node * 2) + \
		make_tree(mid + 1, endidx, node * 2 + 1);
}
ll getquery(int startidx, int endidx, int lidx, int ridx, int node) {
	if (ridx < startidx || lidx > endidx) return 0;
	if (lidx <= startidx && endidx <= ridx) return tree[node];
	int mid = (startidx + endidx) / 2;
	return getquery(startidx, mid, lidx, ridx, node * 2) + \
		getquery(mid + 1, endidx, lidx, ridx, node * 2 + 1);
}

void update_val(int startidx, int endidx, int idx,ll up, int node) {
	
	if (idx < startidx || idx > endidx) return;
	if (startidx==endidx) {
		tree[node] = up;
		return;
	}

	int mid = (startidx + endidx) / 2;
	update_val(startidx, mid, idx, up, node * 2);
	update_val(mid + 1, endidx, idx, up, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b,c;
			cin >> b >> c;
			update.push((make_tuple(0, b, c,0)));
		}
		else
		{
			int b, c, d;
			cin >> b >> c >> d;
			query.push_back(make_tuple(b, c, d,cnt));
			cnt++;
		}
	}
	//기본적으로 오름차순
	make_tree(1, n, 1);


	sort(query.begin(), query.end());
	 cnt = 0;
	for (int i = 0; i < query.size(); i++)
	{
		
		t tup = query[i];
		int val = get<0>(tup);
		int b = get<1>(tup);
		int d= get<2>(tup);
		int q = get<3>(tup);
			while (!update.empty()&&cnt<val)
			{
				t temp= update.front();
				update.pop();
				int q= get<1>(temp);
				int w= get<2>(temp);
				cnt++;
				update_val(1, n, q, w, 1);
			}
			ans.push_back(make_pair(q,getquery(1, n, b, d, 1)));
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].second << "\n";
	}
}