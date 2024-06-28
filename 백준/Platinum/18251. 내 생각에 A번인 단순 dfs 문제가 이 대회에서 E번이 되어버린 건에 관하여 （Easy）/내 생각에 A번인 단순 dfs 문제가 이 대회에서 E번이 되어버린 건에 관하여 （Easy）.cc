#include <iostream>
using namespace std;
#include<limits.h>
#include <vector>
#include <algorithm>
#include<cmath>
#define maxxx 100000
typedef long long ll;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;

int N, dep[270000], idx[270000];
ll d[270000];

int top;
void dfs(int now, int d) {
	if (now > N) return;
	dep[now] = d;
	dfs(now * 2, d + 1);
	idx[top++] = now;
	dfs(now * 2 + 1, d + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> d[i];
	dfs(1, 0);
	ll ans = -inf;
	for (int i = 0; i <= dep[N]; i++) 
		for (int j = i; j <= dep[N]; j++) {
		ll now = -inf;
		for (int k = 0; k < N; k++) {
			if (dep[idx[k]] < i || j < dep[idx[k]]) continue;
			now = max(now + d[idx[k]], d[idx[k]]);
			ans = max(ans, now);
		}
	}
	cout << ans;
	return 0;
}