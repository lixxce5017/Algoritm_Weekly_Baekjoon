#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//효율적인 구간 업데이트를 위해 느리게 갱신되는 세그먼트 트리 사용
//등차수열로 값이 추가 되는것 -> 각 구간들 사이 차이에 1을 더하는것

int n;
long long a[100005];
long long diff[100005]; //[i] = a[i]와 a[i-1]의 차이 (a[i] - a[i-1]) 
int q;
long long sgmtt[400005]; //diff에 대한 합 세그먼트 트리
long long update_check[400005];
vector<long long> output;
#define maxx 1000000
long long make_sgmtt(int here, int left_range, int right_range) {

	if (left_range == right_range) {
		return sgmtt[here] = diff[left_range];
	}

	int mid = (left_range + right_range) / 2;
	int left_child = here * 2 + 1;
	int right_child = here * 2 + 2;
	return sgmtt[here] = make_sgmtt(left_child, left_range, mid) + make_sgmtt(right_child, mid + 1, right_range);
}

long long update_sgmtt(int here, int left_range, int right_range, int left_update, int right_update, long long value) {

	int mid = (left_range + right_range) / 2;
	int left_child = here * 2 + 1;
	int right_child = here * 2 + 2;

	//해당 노드에 업데이트해야 될게 있을때
	if (update_check[here] != 0) {
		sgmtt[here] += (update_check[here] * (right_range - left_range + 1));

		//리프노드가 아닐때 자식 노드로 업데이트 전파
		if (left_range != right_range) {
			update_check[left_child] += update_check[here];
			update_check[right_child] += update_check[here];
		}

		update_check[here] = 0;
	}

	//업데이트 하려는 범위와 상관 없을때
	if (right_update < left_range || right_range < left_update) {
		return sgmtt[here];
	}

	//업데이트 하려는 범위에 속할때
	if (left_update <= left_range && right_range <= right_update) {
		sgmtt[here] += (value * (right_range - left_range + 1));

		//리프노드가 아닐때 자식 노드로 업데이트 전파
		if (left_range != right_range) {
			update_check[left_child] += value;
			update_check[right_child] += value;
		}

		return sgmtt[here];
	}

	return sgmtt[here] = update_sgmtt(left_child, left_range, mid, left_update, right_update, value) + update_sgmtt(right_child, mid + 1, right_range, left_update, right_update, value);
}

//a[x]를 구하기 위해 diff[1]에서 diff[x]까지의 합을 세그먼트 트리를 통해 구한다
//a[x] = diff[1] + diff[2] + ... + diif[x] = -a[0] + a[1] - a[1] + a[2] + ... - a[x-1] + a[x] = -a[0] + a[x] = a[x]
long long query_sgmtt(int here, int left_range, int right_range, int left_find, int right_find) {

	int mid = (left_range + right_range) / 2;
	int left_child = here * 2 + 1;
	int right_child = here * 2 + 2;

	//해당 노드에 업데이트해야 될게 있을때
	if (update_check[here] != 0) {
		sgmtt[here] += (update_check[here] * (right_range - left_range + 1));

		//리프노드가 아닐때 자식 노드로 업데이트 전파
		if (left_range != right_range) {
			update_check[left_child] += update_check[here];
			update_check[right_child] += update_check[here];
		}

		update_check[here] = 0;
	}

	if (left_find <= left_range && right_range <= right_find) {
		return sgmtt[here];
	}

	if (right_find < left_range || right_range < left_find) {
		return 0;
	}

	return query_sgmtt(left_child, left_range, mid, left_find, right_find) + query_sgmtt(right_child, mid + 1, right_range, left_find, right_find);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		long long input;
		cin >> input;
		a[i] = input;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] = a[i] - a[i - 1]; //전 숫자와 차이를 구한다
	}
	make_sgmtt(0, 1, n);

	cin >> q;

	for (int i = 0; i < q; i++) {
		int order;
		int l, r, x;

		cin >> order;

		if (order == 1) {
			cin >> l >> r;
			update_sgmtt(0, 1, n, l, r, 1);
			//for (int i = 1; i < n * 4; i++)
			//{
			//	cout << sgmtt[i] << " ";
			//}
			//cout << "\n";
			//diff[l] ~ diff[r] 까지 모두 1씩 증가했으므로 a[r]과 업데이트가 되지 않은 a[r+1]간의 차이는 r-l+1 만큼 줄어든다 (a[r]은 r-1+1 증가한 반면, a[r+1]은 그대로이다)
			//그러므로 diff[r+1]을 r-l+1 만큼 감소시킨다
			update_sgmtt(0, 1, n, r + 1, r + 1, -(r - l + 1));
		}

		else {
			cin >> x;
			long long result = query_sgmtt(0, 1, n, 1, x);
			output.push_back(result);
		}
	}

	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << "\n";
	}

	return 0;
}