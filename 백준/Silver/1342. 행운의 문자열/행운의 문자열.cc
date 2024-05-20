#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
using namespace std;

vector<bool>visitied;
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>>qq;
vector<long>result;
long long res[100003];
long long res2[100003];
long long res3[100003];
vector <vector<Node>>arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	string s;
	cin >> s;
	int cnt = 0;
	sort(s.begin(), s.end());
	do {
		bool falg = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == s[i + 1])
			{
				falg = false;
				break;
			}
		}
		if (falg == true)
			cnt++;

	} while (next_permutation(s.begin(), s.end()));
	cout << cnt;
}

