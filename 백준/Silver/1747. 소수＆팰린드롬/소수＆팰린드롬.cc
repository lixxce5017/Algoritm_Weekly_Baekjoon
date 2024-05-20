#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

bool ispanldroom(int prime)
{
	string s = to_string(prime);
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
			break;
		}
		start++;
		end--;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long arr[1005000];
	long long n;
	cin >> n;
	for (int i = 2; i < 1004000; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(1004000); i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		for (int j = i + i; j <= 1004000; j = j + i)
		{
			arr[j] = 0;
		}
	}
	int i = n;
	while (true)
	{
		if (arr[i] != 0)
		{
			bool flag = ispanldroom(i);
				if (flag)
				{
					cout << i << "\n";
					break;

			}
		}
		i++;
	}
}
