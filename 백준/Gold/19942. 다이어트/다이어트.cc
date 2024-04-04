#include <iostream>
#include<vector>
#include<tuple>
using namespace std;
int arr[16][5];
int res[4];
int visitied[16];
vector<string>a;
vector<int>coin_val;
int dp[16];
//조합이다
bool trueth=false;
int n;
int min_coin=99999;
int cc=0;
void dfs(int idx,int cnt,int val)
{

    if(idx>=1)
    {
        int ans1=0;
        int ans2=0;
        int ans3=0;
        int ans4=0;
        int ans5=0;
        for(int i=1;i<=n;i++)
        {
            if(visitied[i]==true)
            {
                ans1+=arr[i][0];
                ans2+=arr[i][1];
                ans3+=arr[i][2];
                ans4+=arr[i][3];
                ans5+=arr[i][4];
            }
        }
        //마지막이 벨류
        if(ans1>=res[0]&&ans2>=res[1]&&ans3>=res[2]&&ans4>=res[3])
        {   
            if(min_coin>ans5)
            {
                min_coin=ans5;
                for(int i=1;i<=n;i++)
                {
                    if(visitied[i]==true)
                    {
                        dp[i]=i;
                    }
                    else
                    {
                        dp[i]=0;
                    }
                }
            
            }
 
        }
    }
    for(int i=idx;i<=n;i++)
    {
        if(visitied[i]==true)
        continue;
        
        visitied[i]=true;
        dfs(i+1,cnt+1,0);
        visitied[i]=false;
    }
}
int main()
{
    //이따가 틀렸을때 오름차순으로 해야되는거 출력
    cin>>n;
    cin>>res[0]>>res[1]>>res[2]>>res[3];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    
    a.resize(n+1);

    dfs(0,0,0);
    if(99999!=min_coin)
    {
        cout<<min_coin<<"\n";
        for(int i=1;i<=n;i++)
        {
           if(dp[i]!=0)
           {
               cout<<dp[i]<<" ";
           }
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}