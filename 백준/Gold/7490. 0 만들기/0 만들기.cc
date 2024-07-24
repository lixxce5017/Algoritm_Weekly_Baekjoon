#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int n;

void dfs(int depth,string s,int clunum, string outp)
{
	if (depth == n-1)
	{
		int start = 1;
		int num = 0;
		int ans = 0;
		bool falg = true;
		bool cont = true;
		for (int i = 0; i < s.size(); i++)
		{
			//cout << s[i] << " " << num << " " << ans << "\n";
			if (s[i] == '-')
			{
				falg = false;
				continue;
			}
			else if (s[i] == '+')
			{
				falg = true;
				continue;
			}
			if ((s[i + 1] >= '0') && (s[i + 1] <= '9'))
			{	
				//cout << s[i] << " " << s[i + 1] << "\n";
				if (num == 0)
				{
					num = s[i] - '0';
				}
				else
				num =(num*10) + (s[i] - '0');
			}
			else
			{
				if (falg)
				{
					if (num != 0)
					{
						num = (num * 10) + (s[i] - '0');
						ans += num;
						num = 0;
					}
					else
					{
						ans += (s[i] - '0');
					}
				}
				else
				{
					if (num != 0)
					{
						num = (num * 10) + (s[i] - '0');
						ans -= num;
						num = 0;
					}
					else
					{
						ans -= (s[i] - '0');
					}
				}
			}
			

		}
		//ans += num;
		if (ans == 0)
			cout << outp << "\n";
		return;
	}
	char temp = clunum + '0';


	s += temp;
	outp += " ";
	outp += temp;
	dfs(depth + 1, s, clunum + 1, outp);
	s.pop_back();
	outp.pop_back();
	outp.pop_back();

	s += "+";
	s += temp;
	outp += "+";
	outp += temp;
	dfs(depth + 1, s,clunum+1,outp);
	s.pop_back();
	s.pop_back();
	outp.pop_back();
	outp.pop_back();

	s += "-";
	s += temp;
	outp += "-";
	outp += temp;
	dfs(depth + 1, s,clunum+1, outp);
	//s.pop_back();
	//s.pop_back();
	//outp.pop_back();
	//outp.pop_back();

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int y;
	cin >> y;
	while (y)
	{

		cin >> n;
		string s = "1";
		string outp = "1";
		dfs(0,s,2, outp);
		cout << "\n";
		y--;
	}
}