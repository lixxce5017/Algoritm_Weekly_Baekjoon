#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v_m;
vector<long long> v_p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a, ans = 0;
    long long zero = 0, one = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
            zero = 1;
        else if (a == 1)
            one++;
        else if (a > 0)
            v_p.push_back(a);
        else if (a < 0)
            v_m.push_back(a);
    }

    sort(v_p.begin(), v_p.end(), greater<long long>());
    sort(v_m.begin(), v_m.end());

    /*
    5
    -4
    3
    1
    0
    -8
    양수나 음수가 한개일때 문제가 생김 
    */
    ans = one; // 1은 그대로 더함

    // 음수 처리
    int minus = v_m.size();
    if (minus > 1)
    {
        if (minus % 2 == 0) // 음수가 짝수개 있으면
        {
            for (int i = 0; i < minus; i += 2)
            {
                ans += (v_m[i] * v_m[i + 1]);
            }
        }
        else // 음수가 홀수개 있으면
        {
            for (int i = 0; i < minus - 1; i += 2)
            {
                ans += (v_m[i] * v_m[i + 1]);
            }
            if (zero == 0) // 0이 없으면 마지막 음수 더함
            {
                ans += v_m[minus - 1];
            }
        }
    }
    else if(minus==1)
    {
        if (zero == 0) 
        {
            ans += v_m[minus - 1];
        }
    }

    // 양수 처리
    int plus = v_p.size();
    if (plus > 1)
    {
        if (plus % 2 == 0) // 양수가 짝수개 있으면
        {
            for (int i = 0; i < plus; i += 2)
            {
                ans += (v_p[i] * v_p[i + 1]);
            }
        }
        else // 양수가 홀수개 있으면
        {
            for (int i = 0; i < plus-1; i += 2)
            {
                ans += (v_p[i] * v_p[i + 1]);
            }
            ans += v_p[plus-1]; // 마지막 양수는 단순 더함
        }
    }
    else if(plus==1)
    {
        ans += v_p[0]; 
    }
    

    cout << ans;
}
