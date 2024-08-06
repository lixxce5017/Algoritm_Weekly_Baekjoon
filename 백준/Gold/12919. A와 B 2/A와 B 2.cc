#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
string a, b;
bool ans = 1;
//시간 초과 때문에 ( n이 50) 
//b에서 a로 가서 만들 수 있는지 해야함
void backTracking(string s, int depth)
{
    //cout << s << "\n";
    if (depth == a.size() - 1)
    {
     
        if (s == a)
        {
            cout << 1;
            exit(0);
        }
        return;
    }
    if (s[s.size() - 1] == 'A')
    {
        s.pop_back();
        backTracking(s, depth -1);
        s += "A";
    }
    if(s[0]=='B')
    {
        reverse(s.begin(), s.end());
        s.pop_back();
        backTracking(s, depth -1);
    }




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    backTracking(b, b.size()-1);
    cout << 0;
}
