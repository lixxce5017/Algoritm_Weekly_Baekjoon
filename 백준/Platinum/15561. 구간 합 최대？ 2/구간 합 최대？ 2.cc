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
int u, v;
//걍 만들어 놓고 쿼리만 받음 될 듯
//최솟값 최댓값 찾는 문제처럼 max 
//구간을 어떻게 끌고오지?

//아 다 합친 경의 것도 저장 왼쪽만 선택한 것도 저장 다 비교 때리기
void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].one = (arr[start]*u)+v;
		tree[node].two = (arr[start] *u) + v;
		tree[node].three =(arr[start] * u )+ v;
		tree[node].total2 = (arr[start] *u) + v;
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
		fuck_seg fake = { -INT_MAX,-INT_MAX, -INT_MAX ,-INT_MAX };
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
	//토탈끼리 다 더한게 크냐
	return ans3;
}

void sumation(int node, int start, int end, int idx,ll b)
{
	//cout << node << "\n";
	if (start>idx || end<idx)
	{
		return;
	}
	if (start == end)
	{
		tree[node].one = b * u + v;
		//cout << tree[node].one << "\n";
		tree[node].two = b* u + v;
		tree[node].three = b *u +v;
		tree[node].total2 = b * u + v;
		return;
	}
	int mid = (start + end) / 2;

	sumation(node * 2, start, mid,idx,b);
	sumation(node * 2 + 1, mid + 1, end, idx,b);
	//두개 더한거과 왼쪽만 더큰 것?
	//두개 더한거과 오른쪽 더 큰 것?
	//이따구로 가면 안된다
	//토탈 토탈 맥스도 해야되나? 일단해보고 안되면 ㄱ
	tree[node].two = max(tree[node * 2].two, max(tree[node * 2 + 1].two, tree[node * 2].three + tree[node * 2 + 1].one));
	tree[node].one = max(tree[node * 2].one, tree[node * 2 + 1].one + tree[node * 2].total2);
	tree[node].three = max(tree[node * 2 + 1].three, tree[node * 2].three + tree[node * 2 + 1].total2);
	tree[node].total2 = tree[node * 2 + 1].total2 + tree[node * 2].total2;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n>>m>>u>>v;
	int start = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	init(1, 1, n);
	//for (int i = 1; i <= n * 4; i++)
//	{
	//	cout << tree[i].one << " " << tree[i].two << " " << tree[i].three << " " << tree[i].total2 << "\n";
	//}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 0)
		{ 
			int b, c, q, w;
			cin >> b >> c;
			fuck_seg ww = getQuery(1, 1, n, b, c);
			cout << max(ww.total2, max(ww.one, max(ww.two, ww.three))) - v << "\n";
		}
		else
		{
			int k, b;
			cin >> k >> b;
			sumation(1, 1, n, k, b);
		}

	}

//	for (int i = 1; i <= n * 4; i++)
	//{
	//	cout << tree[i].one << " " << tree[i].two << " " << tree[i].three << " " << tree[i].total2 << "\n";
	//}
	return 0;
}