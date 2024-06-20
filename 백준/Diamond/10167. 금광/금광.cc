#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <cstring>
using namespace std;
typedef long long ll;
struct Node {
	ll sum, l, r, lr;
};
struct p {
	ll y, x, w;
	//bool operator < (const p& t) const {
	//	if (x != t.x) return x < t.x;
	//	return y < t.y;
	
}; int bias = 4096;
Node tree[8300];
bool cmp(p a, p b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

Node f(Node& a, Node& b) {
	Node ret;
	ret.sum = a.sum + b.sum;
	ret.l = max(a.l, a.sum + b.l);
	ret.r = max(b.r, a.r + b.sum);
	ret.lr = max({ a.r + b.l, a.lr, b.lr, ret.sum });
	return ret;
}

void update(int x, int v) {
	x |= bias; tree[x].sum = tree[x].l = tree[x].r = tree[x].lr += v;
	while (x >>= 1) {
		tree[x] = f(tree[x << 1], tree[x << 1 | 1]);
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector < ll > xx;
	vector < ll> yy;
	vector<p> arr;
	for (int i = 0; i < n; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		xx.push_back(x);
		yy.push_back(y);
		arr.push_back({ y,x,w });
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	xx.erase(unique(xx.begin(), xx.end()), xx.end());
	yy.erase(unique(yy.begin(), yy.end()), yy.end());
	for (int i = 0; i < n; i++)
	{
		arr[i].x = lower_bound(xx.begin(), xx.end(), arr[i].x) - xx.begin();
		arr[i].y = lower_bound(yy.begin(), yy.end(), arr[i].y) - yy.begin();
	}
	sort(arr.begin(), arr.end(), cmp);
	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i].y << " " << arr[i].x << " " << "\n";
	}*/
	ll ans = -10e5;
	for (int i = 0; i <n; i++)
	{
		if (i && arr[i - 1].y == arr[i].y) continue;
		for (int k = 0; k < 8300; k++)
		{
			tree[k].l = tree[k].r = tree[k].lr = tree[k].sum = 0;
		}
		for (int j = i; j < n; j++)
		{
			update(arr[j].x, arr[j].w);
			if (j==n-1||arr[j].y != arr[j + 1].y)
			{
				ans = max(ans, tree[1].lr);
			}
		}
	}
	cout << ans;
}