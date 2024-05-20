#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
using namespace std;
static int tree[26][2] = { 0, };
void PERODER(int start)
{
	if (start == -1)
	{
		return;
	}
	//루트
	cout << (char)(start + 'A');
	PERODER(tree[start][0]);
	PERODER(tree[start][1]);
	
}void inODER(int start)
{
	if (start == -1)
	{
		return;
	}
	inODER(tree[start][0]);
	cout << (char)(start + 'A');
	inODER(tree[start][1]);
}
void postODER(int start)
{
	if (start == -1)
	{
		return;
	}
	postODER(tree[start][0]);
	postODER(tree[start][1]);
	cout << (char)(start + 'A');
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char node, left, rigth;
		cin >> node >> left >> rigth;
		int nodeN = node - 'A';

		if (left == '.')
		{
			tree[nodeN][0] = -1;
		}
		else {
			tree[nodeN][0] = left - 'A';
		}
		if (rigth == '.')
		{
			tree[nodeN][1] = -1;
		}
		else {
			tree[nodeN][1] = rigth - 'A';
		}
	}
	PERODER(0);
	cout << "\n";
	inODER(0);
	cout << "\n";
	postODER(0);
	cout << "\n";
	return 0;
}


