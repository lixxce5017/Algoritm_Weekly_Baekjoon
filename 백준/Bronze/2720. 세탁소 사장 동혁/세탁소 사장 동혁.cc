#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
using namespace std;
int coin[4] = { 25,10,5,1 };
int main()
{	
	int t;
	cin >> t;
	while (t)
	{
		int n;
		cin >> n;
		for (int i = 0; i < 4; i++)
		{
			cout << n / coin[i] << " ";
			n %= coin[i];
		}
		cout << "\n";
		t--;
	}
}
