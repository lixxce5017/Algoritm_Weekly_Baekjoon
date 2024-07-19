#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m;
int arr[10];
bool isused[10];



void N_M(int num,int idx)
{

	if (num == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx-1; i <= n; i++)
	{
		if (i == 0)
		{
			continue;
		}
			arr[num] = i;
			N_M(num + 1,i+1);
	}

}
int main(void) {



	cin >> n >> m;
	N_M(0,1);
	return 0;
}
