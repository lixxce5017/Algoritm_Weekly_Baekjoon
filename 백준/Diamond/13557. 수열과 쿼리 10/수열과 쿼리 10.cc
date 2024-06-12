#include <iostream>
#include<vector>
#include<climits>
using namespace std;
#define MAX 500004
typedef long long ll;
struct fuck_seg
{
	ll one; ll two; ll three; ll total2;
};

int arr[MAX];
fuck_seg tree[MAX * 4];
int lazy[MAX * 4];
int in[MAX];
int out[MAX];
int cnt = 1;

void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].one = arr[start];
		tree[node].two = arr[start];
		tree[node].three = arr[start];
		tree[node].total2 = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	tree[node].two = max(tree[node * 2].two, max(tree[node * 2 + 1].two, tree[node * 2].three + tree[node * 2 + 1].one));
	tree[node].one = max(tree[node * 2].one, tree[node * 2 + 1].one + tree[node * 2].total2);
	tree[node].three = max(tree[node * 2 + 1].three, tree[node * 2].three + tree[node * 2 + 1].total2);
	tree[node].total2 = tree[node * 2 + 1].total2 + tree[node * 2].total2;
	return;
}


fuck_seg getQuery(int node, int start, int end, int lidx, int ridx)
{

	if (start > ridx || end < lidx)
	{
		fuck_seg fake = { -INT_MAX,-INT_MAX, -INT_MAX ,0 };
		return fake;
	}
	if (start >= lidx && end <= ridx)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	fuck_seg ans1 = getQuery(node * 2, start, mid, lidx, ridx);
	fuck_seg ans2 = getQuery(node * 2 + 1, mid + 1, end, lidx, ridx);
	fuck_seg ans3;
	ans3.two = max(ans1.three + ans2.one, max(ans1.two, ans2.two));
	ans3.one = max(ans1.one, ans2.one + ans1.total2);
	ans3.three = max(ans2.three, ans1.three + ans2.total2);
	ans3.total2 = ans2.total2 + ans1.total2;
	return ans3;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	int start = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;
	init(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 < x2)
		{
			//무조건 가운데 값은 다 가지고 온 상태에서 들어가야 함 왜??
			//연속합 이니까 ㅋ
			// 3 -2 1 -4 5 2 에서
			//1 2 5 6의 답은 5
			//당연히 중간이 들어가야한다 연속합이니까
			//모르겠음 이 문제가 왜 연속합을 의미하는지를 보자
			//중앙을 안합치면 8이지만 중간을 합치면 5
			//i부터 j의 합이다 ex x1과 y1이 1,3 그 사이인 2가 i x2 5 y2 7 사이으이6이j이다
			// 그럼 a[2]~a[6]부터의 연속된 최대합을 구해야한다 당연히 다른부분도 1~3 과 2~7사이의 모든 연속합 중 최댓값이다.
			//그러므로 중간값은 무조건 포함되어야 한다.
			//무조건 1~3 구간 5~7 구간 사이가 또 포함되어야 하는 이유는 문제에서 i부터 j의 합이라 의미 했기 때문 중간에 있는
			//애들은 i와j로 선택 되지 않는다.
			fuck_seg left = getQuery(1, 1, n, x1, y1);
			fuck_seg mid = getQuery(1, 1, n, y1 + 1, x2 - 1);
			fuck_seg right = getQuery(1, 1, n, x2, y2);
			cout << left.three + mid.total2 + right.one<<"\n";
		}
		else
		{
			//8
			//3 - 2 1 4 5 2 - 1 3
			//	1
			//	1 5 3 8

			//중복된다고 빼고 그런 것 없다.
			//정말 간단히 갈 수 있는 최댓값이 나올 수 있는 부분을 3개의 섹터+전체로 구하고
			//그것들 중 최댓값을 구해주면 된다.
			//금광세그 안의 금광세그는 이런 느낌 때문
			fuck_seg left = getQuery(1, 1, n, x1, x2 - 1);
			fuck_seg mid = getQuery(1, 1, n, x2, y1);
			fuck_seg right = getQuery(1, 1, n, y1 + 1, y2);
			long long ans1 = left.three, ans2 = mid.two, ans3 = right.one, ans4;
			ans1 += mid.one;
			ans3 += mid.three;
			ans4 = left.three + mid.total2 + right.one;
			cout << max(max(ans1, ans2), max(ans3, ans4)) << "\n";
		}


	}


	return 0;
}