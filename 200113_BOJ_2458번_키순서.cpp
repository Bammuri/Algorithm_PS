#include <iostream>
#define INF 987654321
using namespace std;
int N, M, a, b,ans;
int d[505][505];
int con[505];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			d[i][j] = INF;
		}
	}
	

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b] = 1;
	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (d[i][j] != INF) {
				con[i]++; con[j]++;
				if (con[i] == N - 1)ans++;
				if (con[j] == N - 1)ans++;
			}
		}
	}


	cout << ans;
	return 0;
}