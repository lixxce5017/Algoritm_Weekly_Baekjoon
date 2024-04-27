#include <iostream>
#include<vector>
using namespace std;
#define MAX 100003
typedef long long ll;
vector<ll> arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];
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
void propagat(int node, int start, int end)
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
void sumaition(int node, int start, int end, int lidx, ll val)
{
	if (start > lidx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= lidx)
	{
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	
	sumaition(node * 2, start, mid, lidx, val);
	sumaition(node * 2 + 1, mid + 1, end, lidx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	
}

ll getQuery(int node, int start, int end, int lidx, int ridx)
{

	if (start > ridx || end < lidx)
	{
		return 0;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return  getQuery(node * 2, start, mid, lidx, ridx) + getQuery(node * 2 + 1, mid + 1, end, lidx, ridx);

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
	tech(1, 1);
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			sumaition(1, 1, n, in[b], c);

		}
		else
		{
			int b;
			cin >> b;
			cout << getQuery(1, 1, n, in[b], out[b]) << "\n";
		}
	}
	//for (int i = 1; i <= n * 4; i++)
	//{
	//	cout << tree[i] << " ";
	//}
	return 0;
}