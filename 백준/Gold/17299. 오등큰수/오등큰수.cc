#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int arr[1000003] = { 0, };
vector<int>result;
int degree[1000003] = { 0, };
int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		degree[arr[i]]++;
	}
	
	stack<int> mys;
	
	for (int i = n-1; i >=0; i--)
	{
		while (!mys.empty()&& degree[arr[i]]>=degree[mys.top()])
		{
			mys.pop();
		}
		if (mys.empty()==true)
		{
			result.push_back(-1);
		}
		else
		{
			result.push_back(mys.top());
		
		}
			mys.push(arr[i]);
			
	}
	reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}