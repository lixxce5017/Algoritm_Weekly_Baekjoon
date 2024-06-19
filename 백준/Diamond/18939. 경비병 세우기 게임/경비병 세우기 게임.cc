#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <cstring>
using namespace std;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t)
	{

		int n, m, k;
		cin >> n >> m >> k;
		if (max(n, m) < k * 2)
		{
			cout << "Yuto"<<"\n";
		}
		else
		{
			if ((n * m) % 2 ==0)
			{
				cout << "Platina"<<"\n";
			}
			else
			{
				cout << "Yuto"<<"\n";
			}
		}
		t--;
	}
	
	
	
}