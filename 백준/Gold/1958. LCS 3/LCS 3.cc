#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dp[101][101][101];
string s1, s2,s3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s1 >> s2>>s3;


	int s1_Size = s1.size();
	int s2_Size = s2.size();
	int s3_Size = s3.size();

	for (int i = 1; i <= s1_Size; i++)
	{
		for (int j = 1; j <= s2_Size; j++)
		{
			for (int k = 1; k <= s3_Size; k++)
			{
			
				if (s1[i-1] == s2[j-1]&&s1[i-1] == s3[k-1]&&s2[j-1]==s3[k-1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] += max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	cout << dp[s1_Size][s2_Size][s3_Size];

}