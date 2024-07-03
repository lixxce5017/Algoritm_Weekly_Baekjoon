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
using namespace std;
int parent[100003];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
		{
			 s[i]+=32;

		}
		else if(islower(s[i]))
			s[i]-=32;
	}
	cout << s;
}