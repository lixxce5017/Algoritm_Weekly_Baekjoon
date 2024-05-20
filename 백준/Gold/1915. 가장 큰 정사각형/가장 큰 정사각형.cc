#include <iostream>
#include <string>
#include<math.h>
#include<vector>
using namespace std;

int arr[1003][1003] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n,m;
	cin >> n>>m;
	
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j+1] = s[j] - '0';
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][j] = min(arr[i - 1][j-1], min(arr[i][j - 1], arr[i - 1][j]))+1;
				maxx = max(maxx, arr[i][j]);
			}
			
		}
	}

	cout << maxx * maxx << "\n";
	
}