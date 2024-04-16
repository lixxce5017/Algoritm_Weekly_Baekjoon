#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>>arr;
vector<int> val;
vector<int> val_ans;
bool visitied[1000003];
void dfs(int n,int chichan)
{
	//cout << n << " ";
	if (visitied[n] == true)
		return;
	visitied[n] = true;
	for (int i = 0; i < arr[n].size(); i++)
	{
		if (visitied[arr[n][i]] == false)
		{
			val[arr[n][i]] += val[n];
			dfs(arr[n][i],chichan);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	arr.resize(n + 1);
	val.resize(n + 1, 0);
	val_ans.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			continue;
		arr[temp].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int num, Val;
		cin >> num >> Val;
		val[num] += Val;
	}
	/*for (int i = 1; i <= n; i++)
	{
		cout << val[i] << " ";
	}cout << "\n";*/

		dfs(1,1);
		//memset(visitied, false, sizeof(visitied));

	for (int i = 1; i <= n; i++)
	{
		cout << val[i] << " ";
	}
}