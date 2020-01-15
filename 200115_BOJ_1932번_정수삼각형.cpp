#include <iostream>
#include <algorithm>
using namespace std;

int DP[501][501],N,num=0, ans[501][501];


void print() {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << ans[i][j]<<" ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int tmp = N;
	for(int i=0;i<N;i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> DP[i][j];
		}
	}

	ans[0][0] = DP[0][0];

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < i + 1; j++) {

			ans[i + 1][j] = max(ans[i + 1][j], DP[i + 1][j] + ans[i][j]);
			ans[i + 1][j + 1] = max(ans[i + 1][j + 1], DP[i + 1][j + 1] + ans[i][j]);
		}
	}

	//print();
	for (int i = 0; i < N; i++) {
		if (num < ans[N - 1][i])
			num = ans[N - 1][i];

	}
	cout << num;

	return 0;
}