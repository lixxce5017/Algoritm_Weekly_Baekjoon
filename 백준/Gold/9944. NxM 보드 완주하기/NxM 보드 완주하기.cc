#include<iostream>
#include<limits.h>
#include<cstring>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n = 0, m = 0;
int ans,q;
char txt_box[40][40] = { 0 };
bool visited[40][40];
int change_ans = INT_MAX;
int cnt_can_pass;

void dfs(int x, int y, int cnt, int direct,int change) {//dist : 0=d, 1=s, 2=a, 3=w
	//cout << change <<" "<< cnt << '\n';
	//cout << cnt << " ";
	if (cnt == cnt_can_pass) {
		ans = min(change, ans);
		return;
	}
	visited[x][y] = true;
	if (txt_box[x + dx[direct]][y + dy[direct]] == '.' && visited[x + dx[direct]][y + dy[direct]] == false) {
		if(x+dx[direct]>=0&&dy[direct]+y>=0&&x+ dx[direct] <n&&y+dy[direct]<m)
		dfs(x + dx[direct], y + dy[direct], cnt + 1, direct,change);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false && txt_box[nx][ny] == '.') {
				dfs(nx, ny, cnt + 1, i,change+1);

			}
		}
	}
	visited[x][y] = false;
}

int main() {
	while (cin >> n >> m) {
		ans = INT_MAX;
		change_ans = INT_MAX;
		cnt_can_pass = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> txt_box[i][j];
				if (txt_box[i][j] == '.') {
					cnt_can_pass++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (txt_box[i][j] == '.') {
					bool falg = false;
					for (int t = 0; t < 4; t++) {
						int tx = dx[t] + i;
						int ty = dy[t] + j;
						if (tx >= 0 && ty >= 0 && tx < n && ty < m && txt_box[tx][ty] == '.') {
							dfs(i, j, 1, t,1);
							falg = true;
						}
					}
					if (falg==false)
					{
						dfs(i, j, 1, 0, 0);
					}
				}
			}
		}
		for (int i = 0; i < 40; i++) {
			memset(txt_box[i], 0, 40);
	}
		q++;

		if (ans == INT_MAX)
			cout << "Case " << q << ": " << -1 << "\n";
		else
			cout << "Case " << q << ": " << ans << "\n";
		
	}
}