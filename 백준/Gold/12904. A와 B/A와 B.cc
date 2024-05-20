#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include<tuple>
#include<queue>;
#include<string>

using namespace std;
string a, b;
/*void dfs(string s)
{

	if (a == s)
	{
		cout << "1";
		exit(0);
	}
	if (s.size()==0)
	{
		return;
	}
	if (s[s.size() - 1] == 'A')
	{
		s.pop_back();
		dfs(s);
	}
	if (s[s.size() - 1] == 'B')
	{
		reverse(s.begin(), s.end());
		s.pop_back();
		dfs(s);
	}
	
	
}*/
int main()
{	//R이 34, 23 green, blue 18
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	while (1)
	{
		if (b.size() == a.size())
		{
			if (b == a)
			{
				cout << "1";
				return 0;
			}
			break;
		}

		if (b[b.size() - 1] == 'A')
		{
			b.pop_back();
		}
		else
		{
			b.pop_back();
			reverse(b.begin(), b.end());
		}

	}
	cout << 0;
}