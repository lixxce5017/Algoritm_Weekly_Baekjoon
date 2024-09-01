#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> ans(n, 0);
    vector<set<int>> temp(n); // 중복된 값을 피하기 위해 집합을 사용
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (temp[i].find(k) != temp[i].end()) {
                    continue; // 이미 처리된 학생은 건너뜀
                }
                if (i == k) {
                    continue; // 자기 자신은 비교하지 않음
                }
                if (arr[i][j] == arr[k][j]) {
                    cnt++;
                    temp[i].insert(k); // 학생 번호를 저장
                }
            }
            ans[i] += cnt;
        }
    }

    int idx = 0;
    int MaxVal = ans[0];
    for (int i = 0; i < n; i++) {
        if (ans[i] > MaxVal) {
            idx = i;
            MaxVal = ans[i];
        }
    }

    cout << idx + 1 << endl; // 1부터 시작하는 인덱스를 위해 +1

    return 0;
}
