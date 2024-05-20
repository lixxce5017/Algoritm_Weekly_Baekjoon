#include <iostream>
#include <algorithm>
using namespace std;
int arr[200000]={0,};
int main(void)
{
  
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int arr[10001]={0,};
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
    {
      cin>>arr[i];
    }
  sort(arr,arr+t);
  int sum=0;
for(int i=0; i<t; i++)
  { 
    sum+=arr[i] *(t-i);
  }
cout<<sum;
}
