#include <iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;
#define MAX 500004
const int MAXN = 100001;
long long color[MAXN * 4];
vector < long long > arr[202020];
vector<long long> tree[202020 * 4];
int cnt = 0;
int in[202020];
int out[202020];
long long temp[202020];

// 일단 오일러 투어 테크닉을 써서 트리를 배열로 펴주고 나면 각각의 서브트리를 구간으로 나타낼
//. 이제 이 구간에서 루트의 값 x보다 큰 원소의 개수를 세는 문제가 되는데, 
//  lower bound upper 바운드 잘 쓰자 이상 이하 포함 등등 15899 문제와 거의 비슷
void dfs(int node)
{
	in[node] = ++cnt;
	temp[cnt] = color[node];
	//cout << node << "\n";
	for (auto i : arr[node])
	{
		if (in[i]!=0)
		{
			continue;
		}
		dfs(i);
	}
	out[node] = cnt;
}
void init(int node, int start, int end, int idx)
{
	//머지 소트 트리라 다 박아줘야됨
	if (idx<start || idx>end)
	{
		return;
	}
	tree[node].push_back(temp[idx]);
	if (start != end)
	{
		int mid = (start + end) / 2;
		init(node * 2, start, mid, idx);
		init(node * 2 + 1, mid + 1, end, idx);
	}
}
int update(int node, int start, int end, int lidx, int ridx, long long x)
{
	//cout << node << " ";
	if (ridx<start || lidx>end)
	{
		return 0;
	}
	if (start >=lidx && end <= ridx)
	{
		int tmep =  (tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x));
		return tmep;
	}
	int mid = (start + end) / 2;
	return update(node * 2, start, mid, lidx, ridx, x)+ update(node * 2+1, mid+1, end, lidx, ridx, x);
	
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, Q,c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> color[i];
	}
	for (int i = 2; i <=N; i++)
	{
		int a, b;
		cin >> a;
		arr[i].push_back(a);
		arr[a].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		init(1, 1, N, i);
	}
	for (int i = 0; i < N*4; i++) sort(tree[i].begin(), tree[i].end());
	int ans = 0;
	//쿼리
	for (int w = 1; w <=N; w++)
	{
		cout << update(1, 1, N, in[w], out[w], color[w])<<"\n";
	}

	return 0;
}