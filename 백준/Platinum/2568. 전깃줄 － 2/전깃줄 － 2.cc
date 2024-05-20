#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_map>
#include <deque>
#include <string>
#define maxx 1000

using namespace std;

#define lx long long
int n;
vector<pair<int, int>> x;
vector<int> ans, idx;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x.push_back(make_pair(a, b));
	}
	sort(x.begin(), x.end());


	ans.push_back(x.front().second);
	idx.push_back(0);

	for (int i = 1; i < x.size(); i++) {
		int next = x[i].second;
		if (ans.back() < next) {
			ans.push_back(next);
			idx.push_back(ans.size() - 1);
		}
		else {
			int left = 0;
			int right = ans.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (ans[mid] < next) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			ans[left] = next;
			idx.push_back(left);
		}

	}

	cout << x.size() - ans.size() << "\n";


	int now = ans.size() - 1;
	vector<int> sibal;
	for (int i = idx.size() - 1; i >= 0; i--) {
		if (now == idx[i]) {
			now--;
		}
		else {
			sibal.push_back(x[i].first);
		}
	}

	sort(sibal.begin(), sibal.end());
	for (int i : sibal)
		cout << i << "\n";



}