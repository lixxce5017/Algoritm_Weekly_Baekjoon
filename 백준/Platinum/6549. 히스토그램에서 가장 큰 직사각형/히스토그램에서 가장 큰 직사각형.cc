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
struct pos
{
    long long val, node;
};
using namespace std;
long long val[100003];
pos tree[100003 * 4];
int n;
void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].val= val[start];
		tree[node].node = start;
		return;
	}
	int mid=(start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2+1, mid+1, end);
	if (tree[node * 2].val > tree[node * 2 + 1].val)
	{
		tree[node].val = tree[node * 2 + 1].val;
		tree[node].node = tree[node * 2 + 1].node;
	}
	else
	{
		tree[node].val = tree[node * 2].val;
		tree[node].node = tree[node * 2].node;
	}
}

pos query(int node, int start, int end,int left,int right)
{
	if (start > right || end < left) return pos{ LONG_MAX,0 };
	if (start>=left&&end<=right)
	{
		//cout << start << " " << end << " ";
		return tree[node];
	}
	int mid = (start + end) / 2;
	pos a = query(node * 2, start, mid, left, right);
	pos b = query(node * 2 + 1, mid + 1, end, left, right);
	if (a.val > b.val)
		return b;
	else
		return a;
}
long long ans = 0;
 void dfs(int start, int end)
{
	if (start > end)
		return;
	pos tmp = query(1, 1, n, start, end);
	//cout << tmp.node << " "<<tmp.val;
	ans = max(ans, tmp.val * (end - start + 1));
	dfs(start, tmp.node-1);
	dfs(tmp.node+1,end);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
		}
		init(1, 1, n);
		dfs(1, n);
		cout << ans<<"\n";
		ans = 0;
		memset(val, 0, sizeof(val));
		memset(tree, 0, sizeof(tree));
	}
}