#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX 500004

int main()
{
	int n;
	cin >> n;
	int num = 1;
	while (num!=n)
	{
		int temp = num;
		int temp2 = num;
		while (temp)
		{
			temp2+=temp % 10;
			temp = temp / 10;
		}
		if (temp2 == n)
		{
			cout << num;
			return 0;
		}
		num++;
	}
	cout << 0;
	return 0;
}