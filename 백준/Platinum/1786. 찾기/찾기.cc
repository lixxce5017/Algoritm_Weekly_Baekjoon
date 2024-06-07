#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
#define maxx 100000000
ll a = 302;
ll p = 1e9 + 7;
ll powa[1000010];
//라빈 카프로
//kmp로 다시 해보자
// 학교에서 배운대로
//p는 언제나 엄청 큰 값
int main() {
    string T, P; 
    getline(cin, T); getline(cin, P);

    int lenT = T.size();
    int lenP = P.size();
    if (lenT < lenP) {
        cout << 0 << '\n';
        return 0;
    }


    // a의 제곱값을 미리 구해놓음
    powa[0] = 1;
    for (int i = 1; i < P.size(); i++) {
        powa[i] = powa[i - 1] * a % p;
    }

    // 각각 P길이만큼 해시값 구함
    ll hashT = 0;
    ll hashP = 0;

    for (int i = 0; i < P.size(); i++) {
        hashT = (hashT + T[i] * powa[P.size() - 1 - i]) % p;
        hashP = (hashP + P[i] * powa[P.size() - 1 - i]) % p;
    }

    vector<int> rs;
    if (hashT == hashP) rs.push_back(1);

    for (int i = 1; i <= (T.size() - P.size()); i++) {
        // 앞글자 빼고, a만큼 곱해서 한자리씩 올리고, 새로 한글자 추가
        hashT = (hashT - T[i - 1] * powa[P.size() - 1]) % p;
        // 음수인경우 확인
        if (hashT < 0) hashT += p;
        hashT = hashT * a % p;
        hashT = (hashT + T[i + P.size() - 1]) % p;
        if (hashT == hashP) rs.push_back(i + 1);

    }

    cout << rs.size() << '\n';
    for (int x : rs) cout << x << '\n';

    return 0;
}
