#include <iostream>
#include<vector>
#include<climits>
using namespace std;
#define MAX 100003
typedef long long ll;
ll arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;
long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	return tree[node] = min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
void sumaition(int node, int start, int end, int lidx,int ridx, ll val,int cnt)
{
	if (start > lidx || end < lidx)
	{
		return;
	}
	if (start==end)
	{
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	
	sumaition(node * 2, start, mid, lidx, ridx, val,cnt);
	sumaition(node * 2 + 1, mid + 1, end, lidx, ridx, val,cnt);
	tree[node] = min(tree[node * 2],tree[node * 2 + 1]);
	
}

ll getQuery(int node, int start, int end, int lidx, int ridx)
{

	if (start > ridx || end < lidx)
	{
		return INT_MAX;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return  min(getQuery(node * 2, start, mid, lidx, ridx), getQuery(node * 2 + 1, mid + 1, end, lidx, ridx));

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	int start = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	init(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			long long c;
			cin >>b>>c;
			int cnt = 1;
			sumaition(1, 1, n, b,b,c,cnt);

		}
		else
		{
			int b,q;
			cin >> b>>q;
			cout << getQuery(1, 1, n, b, q) << "\n";
		}
	}

	return 0;
}