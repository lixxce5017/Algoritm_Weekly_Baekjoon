#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
#include<queue>
int visitied[14];
int n, s, d,m;
int ans = 0;
int arr[14][14];
int maxx = 0;
//순열
void dfs(int cnt,int sum)
{
	if (cnt == 12)
	{	
		maxx = max(maxx, sum);
	}
	for (int i = 1; i <= 11; i++)
	{
		if (visitied[i] == false && arr[cnt][i]!=0)
		{
			sum += arr[cnt][i];
			visitied[i] = true;
			dfs(cnt + 1,sum);
			sum -= arr[cnt][i];
			visitied[i] = false;
		}
	}
	
}
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t)
	{
		for (int i = 1; i <= 11; i++)
		{
			for (int j = 1; j <= 11; j++)
			{
				cin >> arr[i][j];
			}
		}
		 maxx = 0;
		dfs(1, 0);
		//memset(visitied, false, sizeof(visitied));
		cout << maxx<<"\n";
		t--;
	}

}