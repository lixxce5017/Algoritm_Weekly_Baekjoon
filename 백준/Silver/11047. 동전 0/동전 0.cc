#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
  
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
int n,k;
  int j=0;
int coin[12];
  int cnt=0;
  
cin>>n>>k;
  for(int i=0;i<n;i++)
    {
      cin>>coin[i];
    }
sort(coin,coin+n);
  
  while(1)
    {
      
      if(coin[n-1]<=k)
      { k=k-coin[n-1];
        cnt++;
        }
      else
        n--;
      if(k==0)
        break;
  
    }
  cout<<cnt;
}
