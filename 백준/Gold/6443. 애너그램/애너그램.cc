#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#include<queue>
char arr[21];
bool visitied[21];
using namespace std;
int n;
int minnn = INT_MAX;
int teamNum = 0;
string str;
int len;
void dfs(string s, int idx) {
	if (idx == len - 1) {
		cout << s << '\n';
		return;
	}
	//cout << idx << " ";
	for (int i = idx; i < len; i++) {
		if (i!= idx && s[i] == s[idx])
			continue;
		if (s[i] != s[idx])
		{
			swap(s[i], s[idx]);
		}
		dfs(s, idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test;
	cin >> test;
	while (test) {
		cin >> str;
		len = str.size();
		sort(str.begin(), str.end());
		dfs(str, 0);
		test--;
	}
	return 0;
}

