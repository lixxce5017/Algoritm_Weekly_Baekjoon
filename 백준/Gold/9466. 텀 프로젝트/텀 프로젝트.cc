#include <bits/stdc++.h>

using namespace std;

int t,n;
int arr[1000003];
bool chk[1000003];
int ans=0;
int ans2=0;
int dfs(int node)
{
    if(chk[node]==true){
        return node;
    }
    chk[node]=true;
    int next=dfs(arr[node]);
    ans++;
    if(node==next)
    {
        ans2+=ans;
    }
    return next;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            int a;
            cin>>a;
            arr[i]=a;
        }
        for(int i=1; i<=n; i++){
            if(chk[i]==false)
            {
                dfs(i);
                ans=0;
            }
        }
        cout<<n-ans2<<"\n";
        memset(chk,false,sizeof(chk));
        ans2=0;
    }
}
