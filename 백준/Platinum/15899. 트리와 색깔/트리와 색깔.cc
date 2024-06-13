#include <iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;
#define MAX 500004
const int MAXN = 100001;
int color[MAXN * 4];
vector<int> arr[202020];
vector<int> tree[202020 * 4];
int cnt = 0;
int in[202020];
int out[202020];
int temp[202020];
void dfs(int node)
{
	in[node] = ++cnt;
	temp[cnt] = color[node];
	//cout << node << "\n";
	for (auto i : arr[node])
	{
		if (in[i]!=0)
		{
			continue;
		}
		dfs(i);
	}
	out[node] = cnt;
}
void init(int node, int start, int end, int idx)
{
	//머지 소트 트리라 다 박아줘야됨
	if (idx<start || idx>end)
	{
		return;
	}
	tree[node].push_back(temp[idx]);
	if (start != end)
	{
		int mid = (start + end) / 2;
		init(node * 2, start, mid, idx);
		init(node * 2 + 1, mid + 1, end, idx);
	}
}
int update(int node, int start, int end, int lidx, int ridx, int x)
{
	//cout << node << " ";
	if (ridx<start || lidx>end)
	{
		return 0;
	}
	if (start >=lidx && end <= ridx)
	{
		int tmep = tree[node].size() - (tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x));
		return tmep;
	}
	int mid = (start + end) / 2;
	return update(node * 2, start, mid, lidx, ridx, x)+ update(node * 2+1, mid+1, end, lidx, ridx, x);
	
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, Q,c;
	cin >> N>>Q>>c;
	for (int i = 1; i <= N; i++)
	{
		cin >> color[i];
	}
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		//cout << a << " " << b << "\n";
		arr[b].push_back(a);
		arr[a].push_back(b);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		init(1, 1, N, i);
	}
	for (int i = 0; i < N*4; i++) sort(tree[i].begin(), tree[i].end());
	int ans = 0;
	//쿼리
	for (int w = 0; w < Q; w++)
	{
		int v, c;
		cin >> v >> c;
		//cout << in[v] << " " << out[v] << " ";
		int now = update(1, 1, N, in[v], out[v], c);
		ans += now;
		ans %= 1000000007;
	}
	cout<<ans;
	return 0;
}