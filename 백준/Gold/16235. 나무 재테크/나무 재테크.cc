#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n,m,k;
int Map[11][11];
int nutriec[11][11];

vector<int> tree[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void spring()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tree[i][j].size() == 0)
				continue;

			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> temp;
			int die = 0;

			for (int k = 0; k < tree[i][j].size(); k++)
			{
				int age = tree[i][j][k];
				if (age <= Map[i][j])
				{
					//cout << i << " " << j << "\n";
					Map[i][j] = Map[i][j]-age;
					temp.push_back(age+1);
				}
				else
				{
					die =die+ (age/2);
				}
			}
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
			{
				//cout << temp[k]<<" ";
				tree[i][j].push_back(temp[k]);
			}
			//cout << "\n";
			Map[i][j] =Map[i][j]+ die;
		}
	}
}

void fall_winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				if (tree[i][j][k] % 5 == 0)
				{
					//이따 수정
				//	cout << tree[i][j][k] << " ";
					for (int q = 0; q < 8; q++)
					{
						int nx = dx[q] + i;
						int ny = dy[q] + j;
						if (nx >= 0 && ny >= 0 && nx < n && ny < n)
							tree[nx][ny].push_back(1);
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
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nutriec[i][j];
			Map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, a;
		cin >> x >> y >> a;
		tree[x - 1][y - 1].push_back(a);
	}
	for (int i = 0; i < k; i++)
	{
		spring();
		fall_winter();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Map[i][j] += nutriec[i][j];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += tree[i][j].size();
		}
	}
	cout << cnt;

}
