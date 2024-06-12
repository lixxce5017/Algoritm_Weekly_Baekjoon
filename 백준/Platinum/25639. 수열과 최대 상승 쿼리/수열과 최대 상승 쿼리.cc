#include <iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;
#define MAX 500004
typedef long long ll;
struct fuck_seg
{
	ll one; ll Max; ll Min;
};

int arr[MAX];
fuck_seg tree[MAX * 4];
int lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;

void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].one = 0;
		tree[node].Max = arr[start];
		tree[node].Min = arr[end];
		return;
	}
	int mid = (start + end) / 2;

	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	tree[node].one = max({ tree[node * 2].one,tree[node * 2 + 1].one,tree[node * 2 + 1].Max - tree[node * 2].Min });
	tree[node].Max = max(tree[node * 2].Max, tree[node * 2 + 1].Max);
	tree[node].Min = min(tree[node * 2].Min, tree[node * 2 + 1].Min);
	return;
}

void change(int node, int start, int end, int lidx, ll val)
{

	if (lidx < start || end < lidx)
		return;
	if (start == end)
	{
		tree[node].one = 0;
		tree[node].Max = tree[node].Min = val;
		return;
	}
	int mid = (start+ end) / 2;
	change(node * 2 ,start, mid, lidx, val);
	change(node * 2 + 1,mid + 1, end, lidx, val);
	tree[node].one = max({ tree[node * 2].one, tree[node * 2 + 1].one, tree[node * 2 + 1].Max - tree[node * 2].Min });
	tree[node].Max = max(tree[node * 2].Max, tree[node * 2 + 1].Max);
	tree[node].Min = min(tree[node * 2].Min, tree[node * 2 + 1].Min);
	return;
}
fuck_seg Query(int node, int start, int end, int lidx, int ridx)
{
	if (start > ridx || end < lidx)
	{
		fuck_seg fake = { -1, (ll)(-2e9), (ll)(2e9) };
		return fake;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	fuck_seg ans1 = Query(node * 2, start, mid, lidx, ridx);
	fuck_seg ans2 = Query(node * 2 + 1, mid + 1, end, lidx, ridx);
	fuck_seg ans3;
	ans3.one = max({ ans1.one,ans2.one, ans2.Max -ans1.Min });
	ans3.Max = max(ans1.Max, ans2.Max);
	ans3.Min = min(ans1.Min, ans2.Min);
	return ans3;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, Q;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init(1, 1, N);

	cin >> Q;
	
	for (int i = 0; i < Q; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b; ll val;
			cin >> b >> val;
			change(1, 1, N, b, val);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			fuck_seg ans = Query(1, 1, N, b, c);
			cout << ans.one << "\n";
		}
	}


	return 0;
}