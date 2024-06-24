#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
char arr[7][7];
bool check[100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> Student;
int n;
bool YoN;
void simutaion()
{
	
	for (int k = 0; k < Student.size(); k++)
	{
		int x = Student[k].first;
		int y = Student[k].second;
		for (int i = 0; i < 4; i++)
		{
			 int nx = x + dx[i];
			 int ny = y + dy[i];
			while (nx >= 0 && ny >=0 && nx < n && ny < n)
			{
				
				if (arr[nx][ny] == 'T')
				{
					//cout << "d";
					return;
				}
				else if (arr[nx][ny] == 'W')
				{
					break;

				}
				nx += dx[i];
				ny += dy[i];
				}
			}
		}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}*/
	//cout << "\n";
	cout << "YES";
	exit(0);
	return;
	}


void dfs(int cnt,int idx)
{
	if (cnt == 3)
	{
		simutaion();
		return;
	}
	for (int i = 0; i < n*n; i++)
	{
		if (check[i]==false&&arr[i/n][i%n]=='X')
		{
			check[i] = true;
			arr[i/n][i%n] = 'W';
			dfs(cnt + 1,i+1);
			arr[i/n][i%n] = 'X';
			check[i] = false;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				Student.push_back({ i,j });
			}
		}
	}
	dfs(0,0);
	cout << "NO";
}