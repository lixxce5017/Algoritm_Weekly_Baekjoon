#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
using namespace std;
#define MAX 500004
typedef long long ll;
struct MinSeg
{
	int ans; int per; int suf; int s; int e;
};	
int n, m;
MinSeg tree[200003 * 4];
bitset <2000003> arr;
MinSeg merge(const MinSeg& l, const MinSeg& r, int l_len, int r_len)
{
	MinSeg ret = { 1,l.per,r.suf,l.s,r.e };
		if (l.e ^ r.s)
		{
			if (l_len == l.per)
			{
				ret.per += r.per;
			}
			if (r_len == r.suf)
			{
				ret.suf += l.suf;
			}		
			ret.ans = l.suf + r.per;
		}
		ret.ans = max({ ret.ans,l.ans,r.ans,ret.per,ret.suf });
		return ret;
}
MinSeg update(int node,int start, int end,int idx)
{
	if (start >idx || end < idx)
	{
		return tree[node];
	}
	if (start == end)
	{
		return tree[node] = MinSeg{ 1,1,1,arr[idx],arr[idx]};
	}
	int mid = (start + end) / 2;
	return tree[node] = merge(update(node * 2, start, mid, idx),update(node * 2 + 1, mid + 1, end, idx), mid - start+1, end - mid);

}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		update(1, 1, n, i);
	}
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		arr[a] = arr[a] ^ 1;
		update(1, 1, n, a);
		cout << tree[1].ans << "\n";
	}


	return 0;
}