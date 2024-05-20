#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;

int main()
{	//R이 34, 23 green, blue 18
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, query;
	cin >> n >> m >> query;
	//세로 
	vector<int>row(n+ 1, 0);
	//가로
	vector<int>colum(m + 1, 0);
	for (int i = 0; i < query; i++)
	{
		int q, matrix, v;
		cin >> q >> matrix >> v;
		//가로에 다 더함
		if (q == 1)
		{
			row[matrix - 1] += v;
	
		}
		//세로에 다 더함
		else
		{
			colum[matrix - 1] += v;
		}
	}

	for (int i = 0;i <n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << row[i] + colum[j]<<" ";
		}
		cout << "\n";
	}
}