#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
using namespace std;
typedef tuple<int, int, int> Node;
static vector<Node> arr;
static vector<long> result;
static int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	result.resize(n + 1);

	fill(result.begin(), result.end(), LONG_MAX);


	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(make_tuple(a, b, c));
	}

	result[1] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Node edgs = arr[j];
			int start = get<0>(edgs);
			int end = get<1>(edgs);
			int val = get<2>(edgs);
			if (result[start] != LONG_MAX && result[end] > result[start] + val)

			{
				result[end] = result[start] + val;
			}

		}
	}
		bool check = false;
		for (int i = 0; i < m; i++)
		{
			Node edgs = arr[i];
			int start = get<0>(edgs);
			int end = get<1>(edgs);
			int val = get<2>(edgs);

			if (result[start] != LONG_MAX && result[end] > result[start] + val)
			{
				check = true;
				break;
			}
		}
		if (!check)
		{
			for (int i = 2; i <= n; i++)
			{
				if (result[i] == LONG_MAX)
				{
					cout << "-1" << "\n";
				}
				else
				{
					cout << result[i] << "\n";
				}
			}
		}
		else
		{
			cout << "-1";
		}

	}


