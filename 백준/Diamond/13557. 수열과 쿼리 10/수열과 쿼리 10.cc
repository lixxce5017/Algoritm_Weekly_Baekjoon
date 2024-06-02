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
fuck_seg tree[MAX * 4];
int lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;

void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].one = arr[start];
		tree[node].two = arr[start];
		tree[node].three = arr[start];
		tree[node].total2 = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	tree[node].two = max(tree[node * 2].two, max(tree[node * 2 + 1].two, tree[node * 2].three + tree[node * 2 + 1].one));
	tree[node].one = max(tree[node * 2].one, tree[node * 2 + 1].one + tree[node * 2].total2);
	tree[node].three = max(tree[node * 2 + 1].three, tree[node * 2].three + tree[node * 2 + 1].total2);
	tree[node].total2 = tree[node * 2 + 1].total2 + tree[node * 2].total2;
	return;
}


fuck_seg getQuery(int node, int start, int end, int lidx, int ridx)
{

	if (start > ridx || end < lidx)
	{
		fuck_seg fake = { -INT_MAX,-INT_MAX, -INT_MAX ,0};
		return fake;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	fuck_seg ans1 = getQuery(node * 2, start, mid, lidx, ridx);
	fuck_seg ans2 = getQuery(node * 2 + 1, mid + 1, end, lidx, ridx);
	fuck_seg ans3;
	ans3.two = max(ans1.three + ans2.one, max(ans1.two, ans2.two));
	ans3.one = max(ans1.one, ans2.one + ans1.total2);
	ans3.three = max(ans2.three, ans1.three + ans2.total2);
	ans3.total2 = ans2.total2 + ans1.total2;
	return ans3;
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
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 <x2)
		{
			fuck_seg left = getQuery(1, 1, n, x1, y1);
			fuck_seg mid = getQuery(1, 1, n, y1+1, x2-1);
			fuck_seg right = getQuery(1, 1, n, x2, y2);
			 cout<< left.three + mid.total2 + right.one<<"\n";
		}
		else
		{

			fuck_seg left = getQuery(1, 1, n, x1, x2-1);
			fuck_seg mid = getQuery(1, 1, n, x2, y1);
			fuck_seg right = getQuery(1, 1, n, y1+1, y2);
			long long ans1 = left.three, ans2 = mid.two, ans3 = right.one, ans4;
			ans1 += mid.one;
			ans3 += mid.three;
			ans4 = left.three + mid.total2 + right.one;
			cout << max(max(ans1, ans2), max(ans3, ans4)) << "\n";
		}
		
		
	}


	return 0;
}