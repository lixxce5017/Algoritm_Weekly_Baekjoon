#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int a;
int num_list[11];
int num_list_copied[11];
int oprtr_num[4];
int chk[4];
vector<int>oprtr_list;

int max_num = INT_MIN;
int min_num = INT_MAX;

//맵 복사는 백트래킹&&구현류에서 정말 좋은 아이디어 이지만
//여기서는 필요없다.
void copy_numlist() {
	for (int i = 0; i < a; i++) {
		num_list_copied[i] = num_list[i];
	}
}

void calculating() {
	if (oprtr_list.size() == a - 1) {
		copy_numlist();
		// 계산하는 부분에서 이상하게 계산이 들어가서 답이 안나온 것
		//그냥 정석적으로 계산하면 잘 나옴 답이
		int num = num_list[0];
		int idx = 1;
		for (int i = 0; i < a - 1; i++) {
			if (oprtr_list[i] == 0) {
				num += num_list[idx];
				idx++;
			}
			else if (oprtr_list[i] == 1) {
				num -= num_list[idx];
				idx++;
			}
			else if (oprtr_list[i] == 2) {
				num *= num_list[idx];
				idx++;
			}
			else if (oprtr_list[i] == 3) {
				num /= num_list[idx];
				idx++;;
			}
		}
		//cout << num << " ";
		max_num = max(max_num, num);
		min_num = min(min_num, num);
		return;
	}

	//이 부분은 잘 구현 하였다.
	for (int i = 0; i < 4; i++) {
		if (chk[i] < oprtr_num[i]) {
			chk[i]++;
			oprtr_list.push_back(i);
			calculating();
			chk[i]--;
			oprtr_list.pop_back();
		}
	}
}

int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> num_list[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oprtr_num[i];
	}
	calculating();
	cout << max_num << '\n';
	cout << min_num;
}