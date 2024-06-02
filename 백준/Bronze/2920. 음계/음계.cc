#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX 500004
int arr[11];
int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	int a = 0;
	int b = 0;
	int m = 0;
	for (int i = 1; i < 8; i++)
	{
		if (arr[i - 1] < arr[i])
		{
			a++;
		
		}
		else if (arr[i - 1] > arr[i])
		{
			b++;

		}
		if (a >= 1 && b >= 1)
		{
			cout << "mixed";
			return 0;
		}
	}
	if (a > b)
	{
		cout<<"ascending";
	}
	else
	{
		cout << "descending";
	}
	return 0;
}