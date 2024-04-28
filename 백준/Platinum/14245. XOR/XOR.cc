#include <iostream>
#include<vector>
using namespace std;
#define MAX 500004
typedef long long ll;
int arr[MAX];
int tree[MAX * 4];
int lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;

void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	return;
}
void propagat(int node, int start, int end)
{

	//xor은 교환 분배법칙이 성립함
	if (lazy[node] != 0)
	{	
		//어차피 똑같으니 홀수일때만 연산을 해라
		//어차피 상관없지 않나? 걍 10에 0 xor해도 10인데
		//A⊕A=0 이거 조심h
		//이것 때문에 홀수일 시 에만 시행
		//%2 해주면 무적권 짝수는 0 나오니까
		//xor 연산은 한번하던 두번하던 상관이 없다
		//홀수면 한 번만하는게 맞음 어차피 똑같은거에 똑같은거 하면 또 0나옴
		if ((end - start+1)% 2 == 1)
		{
			tree[node] = tree[node]^lazy[node];
		}
		if (start != end)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];

		}//짝수번 못하게 할려고?
		//의미가 있나?
		lazy[node] = 0;
	}
}
void sumaition(int node, int start, int end, int lidx,int ridx, int val)
{
	propagat(node, start, end);
	if (start > ridx || end < lidx)
	{
		return;
	}
	if (start >= lidx && end <= ridx)
	{
		lazy[node] ^= val;
		propagat(node, start, end);
		return;
	}
	int mid = (start + end) / 2;

	sumaition(node * 2, start, mid, lidx,ridx, val);
	sumaition(node * 2 + 1, mid + 1, end, lidx,ridx, val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int getQuery(int node, int start, int end, int lidx, int ridx)
{
	propagat(node, start, end);
	if (start > ridx || end < lidx)
	{
		return 0;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	int ans1 = getQuery(node * 2, start, mid, lidx, ridx);
	int ans2=  getQuery(node * 2 + 1, mid + 1, end, lidx, ridx);
	return  ans1 ^ ans2;

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
			int b,q,c;
			cin >> b >>q>> c;
			sumaition(1, 1, n, b+1,q+1, c);
		}
		else
		{
			int b,c;
			cin >> b;
			cout << getQuery(1, 1, n,b+1,b+1) << "\n";
		}
	}

	return 0;
}