#include <iostream>
#include <string>
#include <vector>
#define maxx 19912
using namespace std;
//kmp 다음주 시험전에 다시 이걸로 보자
vector<int> fail(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[j] != s[i]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    string T, P; getline(cin, T); getline(cin, P);

    vector<int> f = fail(P);

    int j = 0;
    vector<int> rs;
    for (int i = 0; i < T.size(); i++) {
        while (j > 0 && T[i] != P[j]) j = f[j - 1];
        if (T[i] == P[j]) j++;
        if (j == P.size()) {
            rs.push_back(i + 2 - P.size());
            j = f[j - 1];
        }
    }

    cout << rs.size() << '\n';
    for (int x : rs) cout << x << '\n';
    return 0;
}


