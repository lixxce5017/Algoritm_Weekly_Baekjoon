#include <iostream>
#include<vector>
using namespace std;
#define MAX 200003
typedef long long ll;
vector<ll> arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;
int depth[MAX];
//오일러 투어 테크닉 +세그멘트
//1에서 5를 간다면 1,2,3 각각 1씩 더해주고
//깊이를 먼저 구해 그 깊이만큼 곱해주면 답이 나온다.
void tech(int node, int per)
{
	in[node] = cnt++;

	for (auto i : arr[node])
	{
		if (in[i]==0)
		{
			depth[i] = depth[node]+1;
			tech(i, node);
		}
	}
	out[node] = cnt - 1;
}

void sumaition(int node, int start, int end, int lidx)
{
	if (start > lidx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= lidx)
	{
		tree[node] ++;
		return;
	}
	int mid = (start + end) / 2;

	sumaition(node * 2, start, mid, lidx);
	sumaition(node * 2 + 1, mid + 1, end, lidx);
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
	for (int i = 1; i <= n-1; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	depth[m] = 1;
	tech(m, m);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			long long c;
			cin >> b;
			sumaition(1, 1, n, in[b]);

		}
		else
		{
			int b;
			cin >> b;
			//cout << in[b] << " " << out[b] << "\n";
			cout << getQuery(1, 1, n, in[b], out[b])*depth[b] << "\n";
		}
	}
	//for (int i = 1; i <= n * 4; i++)
	//{
	//	cout << tree[i] << " ";
	//}
	return 0;
}