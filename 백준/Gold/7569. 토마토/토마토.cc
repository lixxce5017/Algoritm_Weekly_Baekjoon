#include <iostream>
#include <queue>
#include<tuple>
using namespace std;
typedef tuple <int, int, int> tupl;
long long  tomatoMap[100][100][100];
queue<tupl> q;
int result = 0;
int M, N,K;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
void tomatoBFS() {
	while (!q.empty()) {
		tupl now = q.front();
		int xx = get<1>(now);
		int yy = get<2>(now);
		int zz= get<0>(now);

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			int nz = zz + dz[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && nz >= 0 && nz < K) {
				if (tomatoMap[nz][nx][ny] == 0) {
					tomatoMap[nz][nx][ny] = tomatoMap[zz][xx][yy] + 1;
					q.push(tupl(nz, nx,ny));
				}
			}
		}
	}
}

void tomato() {
	cin >> M >> N>>K;

	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				
					cin >> tomatoMap[k][i][j];

					if (tomatoMap[k][i][j] == 1) {
						q.push(tupl(k, i, j));
					}
				}
			}
		}
	
	tomatoBFS();

	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
					if (tomatoMap[k][i][j] == 0) {
						cout << -1 << "\n";
						return;
					}

					if (result < tomatoMap[k][i][j]) {
						result = tomatoMap[k][i][j];
					}
			}
		}
	}

	cout << result-1<< "\n";

}
int main() {
	tomato();

	return 0;
}