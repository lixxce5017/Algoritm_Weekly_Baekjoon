#include <iostream>
#include <vector>
#include<queue>
#include<tuple>
using namespace std;

long gcd(long a, long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, (a %b));
	
}


int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long a, b;
	cin >> a >> b;
	
	int qqqq = gcd(a,b);

	for (int i = 0; i <qqqq; i++)
	{
		cout << 1;
	}
	
}