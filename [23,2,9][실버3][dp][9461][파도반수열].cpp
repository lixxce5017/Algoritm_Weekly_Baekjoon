#include <iostream>
#include <algorithm>
using namespace std;
long long dp[110]={0,};
int main(void)
{
  //F[N] = F[N - 1] + F[N - 5]
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
int n,k;
dp[1]=dp[2]=dp[3]=1;
dp[4]=dp[5]=2;
cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>k;
      for(int j=6;j<=k;j++)
        {
         dp[j] = dp[j-1] +dp[j-5];
        }
      cout<<dp[k]<<"\n";
    }

}
