#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>

using namespace std;

int main() {
	
	int arr[100] = { 0, };
	for (int i = 0; i <= 20; i++)
	{
		arr[i] = i;
	}
	for(int i=0;i<10;i++)
	{
		int a, bb;
		cin >> a >> bb;
		while (1)
		{
			swap(arr[a], arr[bb]);
			if (bb - a == 1 || bb - a == 0)
				break;

			a++; bb--;
		}

	}
	for (int i = 1; i <= 20; i++)
	{
		cout << arr[i] << "\n";
	}
}