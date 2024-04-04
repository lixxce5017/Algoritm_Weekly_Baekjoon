#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#include<queue>
char arr[21];
bool visitied[21];
long long res=0;
using namespace std;
string s;
int cnt = 0;
void dfs(long long val, int idx, bool tureth, int acnt, int bcnt) {

	if (acnt == 3 || bcnt == 3)
		return;
	//cout << acnt << " " << bcnt << " " << val << "\n";
	if (idx == s.size())
	{
		if(tureth==true)
			res += val;
		return;
	}
	if (s[idx] == '_')
	{
		dfs(val * 5, idx + 1, tureth, acnt + 1, 0);
		dfs(val * 20, idx + 1, tureth, 0, bcnt+1);
		dfs(val, idx + 1, true, 0, bcnt+1);
	}
	else if (s[idx] == 'A' || s[idx] == 'E' || s[idx] == 'I' || s[idx] == 'O' || s[idx] == 'U')
	{
			dfs(val, idx + 1, tureth, acnt + 1, 0);
	}
	else
	{
		if (s[idx] == 'L')
		{
			dfs(val, idx + 1, true,0, bcnt+1);
		}
		else
		{
			dfs(val, idx + 1, tureth, 0, bcnt + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	dfs(1, 0, false, 0, 0);
	cout << res;
	return 0;
}

