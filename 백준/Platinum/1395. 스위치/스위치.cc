#include <iostream>
#include<vector>
#include<climits>
using namespace std;
#define MAX 500004
typedef long long ll;
struct fuck_seg
{
	ll one; ll two; ll three; ll total2;
};

int arr[MAX];
int tree[MAX * 4];
int lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;
int u, v;
void propagate(int node, int start, int end)
{
	if (lazy[node]!= 0)
	{
		if (lazy[node] % 2 != 0)
		{
			tree[node] =(end-start+1)-tree[node];
		}
\
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}


ll getQuery(int node, int start, int end, int lidx, int ridx)
{
	propagate(node, start, end);
	if (start > ridx || end < lidx)
	{
		return 0;
	}
	if (start >=lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return getQuery(node * 2, start,mid, lidx, ridx)+getQuery(node * 2 + 1, mid + 1,end, lidx, ridx);
	
}

void sumation(int node, int start, int end, int lidx,int ridx)
{
	propagate(node, start, end);

	if (start > ridx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= ridx)
	{
		lazy[node] += 1;
		propagate(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	sumation(node * 2, start, mid, lidx, ridx);
	sumation(node * 2 + 1, mid + 1, end, lidx, ridx);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int start = 0;
	for (int i = 0; i < m; i++)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			int a, b;
			cin >> a >> b;
			cout<<getQuery(1, 1, n, a, b)<<"\n";
		}
		else
		{
			int a, b;
			cin >> a >> b;
			sumation(1, 1, n, a, b);
		}
	}
	//for (int i = 1; i <= n * 4; i++)
//	{
	//	cout << tree[i].one << " " << tree[i].two << " " << tree[i].three << " " << tree[i].total2 << "\n";
	//}

//	for (int i = 1; i <= n * 4; i++)
	//{
	//	cout << tree[i].one << " " << tree[i].two << " " << tree[i].three << " " << tree[i].total2 << "\n";
	//}
	return 0;
}