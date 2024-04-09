#include <iostream>
#include <string>
using namespace std;
#include<set>
#include<map>
int main() {
	
	set<pair<int, int>> s;
	map<int, int>dic;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, val;
		cin >> t >> val;
		//앞이 난이도 뒤가 번호
		s.insert(make_pair(val,t));
		dic[t] = val;
	}
	/*for (auto i : s)
	{
		cout << i.first << " " << i.second << "\n";
	}*/
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string sign;
		cin >> sign;
		if (sign == "add")
		{
			int t, val;
			cin >> t >> val;
			s.insert(make_pair(val, t));
			dic[t] = val;
		}
		else if (sign == "recommend")
		{
			int q;
			cin >> q;
			if (q == 1)
			{
				auto temp = s.rbegin();
				cout << temp->second << "\n";;
			}
			else if(q==-1)
			{
				auto temp = s.begin();
				cout << temp->second << "\n";
			}

		}
		else if (sign == "solved")
		{
			int t;
			cin >> t;
			s.erase({ dic[t],t });
			dic.erase(t);
		}
	}
}