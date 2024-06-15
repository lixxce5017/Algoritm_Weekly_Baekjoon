#include <iostream>
#include<vector>
using namespace std;
#define MAX 100003
typedef long long ll;
vector<ll> arr[MAX];
vector<ll>tree_1(4000000);
vector<ll>lazy_1(4000000);
vector<ll>tree_2(4000000);
vector<ll>lazy_2(4000000);
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
	if (lazy[node] != 0)
	{
		tree[node] += (lazy[node] * (end - start + 1));
		if (start != end)
		{
			//리프 노드가 아니니 내 레이즈 갱신하고
			//씨 발 머드라?
			//하위 노드 갱신 트리에 값이었나? 레이즈 갱신이었나?
			//그치 하위에 내 레이즈값 물려주고 0때려줘야
			//다음 애들 갱신할 타이밍때 하지 ㅇㅈ?~ㅇㅇㅈ~
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];

		}
		lazy[node] = 0;
	}
}
void sumaition(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int lidx,int ridx, ll val)
{
	propagat(tree, lazy, node, start, end);
	if (start > ridx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= ridx)
	{
		tree[node] += (val * (end - start + 1));
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;

	sumaition(tree,lazy,node * 2, start, mid, lidx, ridx, val);
	sumaition(tree, lazy,node * 2 + 1, mid + 1, end, lidx, ridx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

ll getQuery(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int lidx, int ridx)
{
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
	return  getQuery(tree, lazy,node * 2, start, mid, lidx, ridx) + getQuery(tree, lazy,node * 2 + 1, mid + 1, end, lidx, ridx);

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int start = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
		{
			start = i;
		}
		else {
			arr[temp].push_back(i);
		}
	}

	tech(start, 1);
	int r=0;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			if(r%2==0)
			sumaition(tree_1,lazy_1,1, 1, n, in[b],out[b],c);
			else
				sumaition(tree_2, lazy_2, 1, 1, n, in[b], in[b],c);

		}
		else if(a==2)
		{
			int b;
			cin >> b;
			ll res1 = getQuery(tree_1, lazy_1,1, 1, n, in[b], in[b]);
			ll res2 = getQuery(tree_2, lazy_2, 1, 1, n, in[b], out[b]);
			cout << res1 + res2<<"\n";
		}
		else
		{
			r++;
		}
	}
	//for (int i = 1; i <= n * 4; i++)
	//{
	//	cout << tree[i] << " ";
	//}
	return 0;
}