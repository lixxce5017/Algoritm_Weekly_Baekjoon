#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<vector<int>>arr;

vector<int> val_ans;
bool visitied[1000003];
int dfs(int n,int chichan)
{
	if (arr[n].empty())
	{
		return 1;
	}vector<int> val;
	for (int i = 0; i < arr[n].size(); i++)
	{
		val.push_back(dfs(arr[n][i], 1) + 1);
	}
	int ret = 0;
	sort(val.begin(), val.end(), greater<int>());
	for (int i = 0; i < val.size(); i++)
	{
		ret = max(ret, val[i] + i);
	}
	return ret;
}
int main()
{
	int n, m;
	cin >> n;
	arr.resize(n + 1);
	val_ans.resize(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			continue;
		arr[temp].push_back(i);
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << val[i] << " ";
	}cout << "\n";*/

		cout<<dfs(0,1)-1;
		//memset(visitied, false, sizeof(visitied));


}