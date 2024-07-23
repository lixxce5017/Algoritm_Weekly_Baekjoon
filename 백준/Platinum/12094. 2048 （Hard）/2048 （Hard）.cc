#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int Map[20][20];
int tumleing[11];
int n;
int ans = 0;
void grvity(int dir);
//가지치기 1. 테트로미노처럼 현재 최댓값이 남은걸 더해도
//답이 될 수 없는 경우

//가지치기 2. 맵이 아예 바뀌지 않았다면 의미가 없는것
bool chek(int temp1[20][20], int temp2[20][20])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (temp1[i][j] != temp2[i][j])
			{
				return true;
			}
		}
	}
	return false;
}
//배열은 포인터니까 * 연산자 안써도 되고 알아서 바뀜
void copy_M(int temp1[20][20], int temp2[20][20])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp1[i][j] = temp2[i][j];
		}
	}
}
int Max_Val(int temp[20][20])
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt = max(cnt, temp[i][j]);
		}
	}
	return cnt;
}

void dfs(int depth)
{

	int v = Max_Val(Map);
	//cout << depth << " ";
	if (v <= tumleing[depth])
		return;
	if (depth == 10)
	{
		ans= max(v, ans);
		v = ans;
		while (depth > 0)
		{
			tumleing[depth--] = v;
			v = v / 2;
		}

		return;
	}
	
	int copyMap[20][20];
	copy_M(copyMap, Map);
	for (int i = 0; i < 4; i++)
	{
		grvity(i);
		if (chek(Map,copyMap) == true)
		{
			dfs(depth + 1);
			copy_M(Map, copyMap);
		}

	}
}

void grvity(int dir)
{
	
	if (dir == 0)
	{
		for (int i = 0; i < n; i++)
		{
			int idx = 0;
			for (int j = 0; j < n; j++)
			{
				if (Map[i][j] != 0)
				{
					int v = Map[i][j];
					Map[i][j] = 0;
					if (Map[i][idx] == v)
					{
						Map[i][idx] = v * 2;
						idx++;
					}
					else if (Map[i][idx] == 0)
					{
						Map[i][idx] = v;
					}
					else
					{
						idx++;
						Map[i][idx] = v;
					}
				}
			}
		}
	}

	else if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int idx = n-1;
			for (int j = n-1; j >=0 ; j--)
			{
				if (Map[i][j] != 0)
				{
					int v = Map[i][j];
					Map[i][j] = 0;
					if (Map[i][idx] == v)
					{
						Map[i][idx] = v * 2;
						idx--;
					}
					else if (Map[i][idx] == 0)
					{
						Map[i][idx] = v;
					}
					else
					{
						idx--;
						Map[i][idx] = v;
					}
				}
			}
		}
	}

	else if (dir == 2)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = 0;
			for (int i = 0; i < n; i++)
			{
				
				if (Map[i][j] != 0)
				{
					int tempval = Map[i][j];
					Map[i][j] = 0;
					if (Map[idx][j] == tempval)
					{
						Map[idx][j] = tempval * 2;
						idx++;
					}
					else if (Map[idx][j] == 0)
					{
					
						Map[idx][j] = tempval;
					}
					else
					{
						idx++;
						Map[idx][j] = tempval;
					}
				}
			}
		}
	}

	else
	{
		for (int j = 0; j < n; j++)
		{
			int idx = n-1; 
			for (int i = n-1; i >=0; i--)
			{

				if (Map[i][j] != 0)
				{
					int tempval = Map[i][j];
					Map[i][j] = 0;
					if (Map[idx][j] == tempval)
					{
						Map[idx][j] = tempval * 2;
						idx--;
					}
					else if (Map[idx][j] == 0)
					{

						Map[idx][j] = tempval;
					}
					else
					{
						idx--;
						Map[idx][j] = tempval;
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}
	ans = Max_Val(Map);
	dfs(0);
	cout << ans;
}