#include <iostream>
#include <algorithm>
#define INF 1000001
using namespace std;


int from;

struct edge {
	int to, val;
};

edge eg;
int N, M, D[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = (i == j) ? 0 : INF;
		}
	}



	for (int i = 0; i < M; i++) {
		cin >> from >> eg.to >> eg.val;
		if(D[from][eg.to] > eg.val)
			D[from][eg.to] = eg.val;
	}



	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int can = min(D[i][j], D[i][k] + D[k][j]);
				if (D[i][j] > can)
					D[i][j] = can;
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] == INF)
				cout << 0<<" ";
			else
				cout << D[i][j]<<" ";
		}
		cout << "\n";
	}




	return 0;
}