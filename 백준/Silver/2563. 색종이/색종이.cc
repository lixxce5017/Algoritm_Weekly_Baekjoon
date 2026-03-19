#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int arr[101][101] = { 0, };
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int i = a; i < a + 10; i++)
		{
			for (int j = b; j <b + 10; j++)
			{

				arr[i][j] = 1;

			}
		}
	}

	for (int i = 1; i <=100; i++)
	{
		for (int j =1; j <=100; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt++;
		}
		}
	}
	cout << cnt;
	return 0;
}