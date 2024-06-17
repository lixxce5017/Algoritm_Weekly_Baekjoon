#include <iostream>
#include<vector>
using namespace std;
#define MAX 100003
typedef long long ll;
vector<ll> arr[MAX];
vector<ll>tree_1(4000000);
vector<ll>lazy_1(4000000);
//스위치 프로파게이션 문제랑 다름
//다 0으로 만들든지 다 1로 만드는거임
//즉 1인 애가 반전되서 0이되는게 아니라 그대로 1임 토글이 아님
//0과 1로 프로파게이션이 되기 때문에
//레이지가 0이 아니면 조건 보면안됨 레이지 -1로 초기화

int in[MAX];
int out[MAX];
int cnt = 1;

void tech(int node, int per)
{
	in[node] = cnt++;
	for (auto i : arr[node])
	{
		if (i != per)
		{
			tech(i, node);
		}
	}
	out[node] = cnt - 1;
}
void propagat(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end)
{
	if (lazy[node] != -1)
	{
		tree[node]= (ll)(end - start + 1)* lazy[node];
		if (start != end)
		{
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}
void sumaition(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int lidx, int ridx, ll val)
{
	propagat(tree, lazy, node, start, end);
	if (start > ridx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= ridx)
	{
		lazy[node] = val;
		propagat(tree,lazy,node, start, end);
		return;
	}
	int mid = (start + end) / 2;

	sumaition(tree, lazy, node * 2, start, mid, lidx, ridx, val);
	sumaition(tree, lazy, node * 2 + 1, mid + 1, end, lidx, ridx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

ll getQuery(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int lidx, int ridx)
{
	//cout << tree[node] << "\n";
	propagat(tree, lazy, node, start, end);
	if (start > ridx || end < lidx)
	{
		return 0;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return  getQuery(tree, lazy, node * 2, start, mid, lidx, ridx) + getQuery(tree, lazy, node * 2 + 1, mid + 1, end, lidx, ridx);

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	int start = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			start = i;
		}
		else {
			arr[temp].push_back(i);
		}
	}
	tech(start, 1);
	cin >> m;
	sumaition(tree_1, lazy_1, 1,1, n, in[1], out[1], 1);
	int r = 0;
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a>>b;
		if (a == 1)
		{
			sumaition(tree_1, lazy_1, 1, 1, n, in[b]+1, out[b], 1);
		}
		else if (a== 2)
		{
			sumaition(tree_1, lazy_1, 1, 1, n, in[b]+1, out[b], 0);
		}
		else
		{
			cout<< getQuery(tree_1, lazy_1, 1, 1, n, in[b]+1, out[b])<<"\n";
		}
	}

	return 0;
}