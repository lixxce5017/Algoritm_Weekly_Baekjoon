#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int Maxx = 0;
	int Minn = 987654321;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		Maxx = max(num, Maxx);
		Minn = min(num, Minn);
	}
	if(Maxx%2==0)
	cout << Maxx * 2;
	else
	{
		cout << Maxx * Minn;
	}
}
