#include <iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;
#define MAX 500004
const int MAXN = 100001;


vector<int> tree[MAXN * 4];
void init(int node, int start, int end, int val, int idx)
{
	//머지 소트 트리라 다 박아줘야됨
	if (idx<start || idx>end)
	{
		return;
	}
	tree[node].push_back(val);
	if (start != end)
	{
		int mid = (start + end) / 2;
		init(node * 2, start, mid, val, idx);
		init(node * 2 + 1, mid + 1, end, val, idx);
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
		int tmep = tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(),x);
		return tmep;
	}
	int mid = (start + end) / 2;
	return update(node * 2, start, mid, lidx, ridx, x)+ update(node * 2+1, mid+1, end, lidx, ridx, x);
	
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, Q;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		init(1, 1, N, num, i);
	}
	for (int i = 0; i < N * 4; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	cin >> Q;
	int last = 0;
	for (int w = 0; w < Q; w++)
	{
		int  i, j, k;
		cin >> i >> j >> k;
		i = i ^ last;
		j = j ^ last;
		k = k ^ last;
		last = update(1, 1, N, i, j, k);
		cout << last << "\n";
	}
	return 0;
}