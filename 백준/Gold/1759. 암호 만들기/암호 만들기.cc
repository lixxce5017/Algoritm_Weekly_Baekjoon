#include <iostream>
#include<algorithm>
using namespace std;
int n, m;
char s[20];
int ans[20];
bool visitied[25];

bool CehPass()
{
	int cnt=0;
	int recnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[ans[i]] == 'a' || s[ans[i]] == 'e' || s[ans[i]] == 'i' || s[ans[i]] == 'o' || s[ans[i]] == 'u')
		{
			cnt++;
		}
		else
		{
			recnt++;
		}
	}
	if (cnt>=1&&recnt>=2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dfs(int idx,int cnt)
{

	if (cnt == m)
	{
		if (CehPass() == true)
		{
			for (int i = 0; i < m; i++)
			{
				cout << s[ans[i]];
			}
			cout << "\n";
			return;
		}
		else
		{
			return;
		}
	}

	for (int i = idx; i <n; i++)
	{
		if (visitied[i] == false)
		{
			visitied[i] = true;
			ans[cnt] = i;
			dfs(i + 1, cnt + 1);
			visitied[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s+n);
	dfs(0,0);
}
