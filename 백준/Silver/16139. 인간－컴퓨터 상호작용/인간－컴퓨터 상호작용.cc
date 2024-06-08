#include <iostream>
#include <string>
using namespace std;
#define maxxx 10000;
int sum[200001][27];

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string S;
	int q;

	cin >> S;
	sum[0][S[0] - 'a']++;
	for (int i = 1; i < S.length(); i++) {
		for (int j = 0; j < 26; j++)
			sum[i][j] = sum[i - 1][j];

		sum[i][S[i] - 'a']++;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		char alphabet;
		int l, r;
		cin >> alphabet >> l >> r;

		int count1 = l > 0 ? sum[l - 1][alphabet - 'a'] : 0;
		int count2 = sum[r][alphabet - 'a'];

		cout << count2 - count1 << "\n";
	}

	return 0;
}
