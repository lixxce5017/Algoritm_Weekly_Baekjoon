#include <bits/stdc++.h>

using namespace std;

int n,k;
bool chk[100005];
queue <pair<int,int>> q;

void bfs(int start)
{
    q.push({start,0});
    chk[start]=true;
    while(!q.empty()){
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        if(nx==k){
            cout<<ny;
            return;
        }
        if(nx+1<=100000&&chk[nx+1]==false ){
            chk[nx+1]=true;
            q.push({nx+1,ny+1});
        }
        if(nx-1>=0&&chk[nx-1]==false){
            chk[nx-1]=true;
            q.push({nx-1,ny+1});
        }
        if(nx*2<=100000&&chk[nx*2]==false ){
            chk[nx*2]=true;
            q.push({nx*2,ny+1});
        }
    }
}
int main()
{
    cin>>n>>k;
    bfs(n);
    return 0;
}
