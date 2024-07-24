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
long long maxx = 0;
long long minn = 9987654321;
bool vsitieid[10];
string max_ans;
string min_ans;
void dfs(int depth,string s, long long num,int per, string ans)
{
	if (n== depth)
	{
		if (num > maxx)
		{
			maxx = num;
			max_ans = ans;
		}
		if (num < minn)
		{
			minn = num;
			min_ans = ans;
		}
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (vsitieid[i] == false)
		{

			if (s[depth] == '<')
			{
				if (per < i)
				{
					ans.push_back(i + '0');
					vsitieid[i] = true;
					dfs(depth + 1, s, (num * 10) + i, i,ans);
					vsitieid[i] = false;
					ans.pop_back();
				}
			}
			else
			{
				if (per > i)
				{
					ans.push_back(i + '0');
					vsitieid[i] = true;
					dfs(depth + 1, s, (num * 10) + i, i,ans);
					vsitieid[i] = false;
					ans.pop_back();
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> n;
	cin.ignore();
	//이렇게 입력받으면 n을 입력받고 엔터를 누른 엔터가
	//버퍼에 남아 있어서 엔터가 버퍼에 있는걸 무시해주는 
	//cin.ignore()가 필요하다.
	getline(cin,s);
	//공백제거
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	for (int i = 0; i <= 9; i++)
	{
		string q;
		q+=i + '0';
		vsitieid[i] = true;
		dfs(0, s, i, i, q);
		vsitieid[i] = false;
	}
	cout << max_ans << "\n" << min_ans;

}