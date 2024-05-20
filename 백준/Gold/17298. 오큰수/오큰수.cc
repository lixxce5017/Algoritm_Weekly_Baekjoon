#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> sequence;
int n;
int arr[1000001];
int result[1000001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		while (!sequence.empty() && arr[i] > arr[sequence.top()])
		{
			int num = sequence.top();
			result[num] = arr[i];
			sequence.pop();
			
		}
		sequence.push(i);

	}
	while (!sequence.empty())
	{
		int num = sequence.top();
		result[num] = -1;
		sequence.pop();
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << " ";
	}

	
}