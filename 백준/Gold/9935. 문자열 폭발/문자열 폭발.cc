#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include<stack>

#define MAX 1000001
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    string target;
    cin >> target;
    stack<char>myq;
  //  cout << s << " " << target << " ";
    for (int i = 0; i < s.size(); i++)
    {
        //cout << s[i];
       // cout << s[i] << " ";
      //acddd
       // abcd
        //123 12
            if (s[i] == target[target.size() - 1]&&myq.size()>=target.size()-1)
            {
                //cout << s[i] << " ";
                string temp;
                temp += target[target.size() - 1];
                //cout << temp;
                int siz = target.size() - 1;
                while (siz >0)
                {

                    char t = myq.top();
                    myq.pop();
                    temp.push_back(t);
                    siz--;
                }
                
                reverse(temp.begin(), temp.end());
                if (temp == target)
                {
                    continue;
                }
                else
                {
                    //다시 꼽아 놓기
                    int ts = 0;
                    while (ts < temp.size())
                    {
                        myq.push(temp[ts]);
                        ts++;
                    }
                }
            }
        else
        {
            myq.push(s[i]);
        }
    }
    string res;
    while (!myq.empty())
    {
        res += myq.top();
        myq.pop();
    }
    if(res.size()>0)
    reverse(res.begin(), res.end());
    if (res.size() > 0)
    {
        cout << res;
    }
    else
    {
        cout << "FRULA";
    }
    return 0;
}