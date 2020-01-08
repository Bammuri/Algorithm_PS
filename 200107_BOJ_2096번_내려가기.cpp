#include <iostream>
#include <algorithm>
using namespace std;
int map[100000][3],N;
int DP[2][3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	DP[0][0] = map[0][0];
	DP[0][1] = map[0][1];
	DP[0][2] = map[0][2];
	for (int i = 1; i < N; i++) {
		DP[i%2][0] = max(DP[(i - 1)%2][0], DP[(i - 1) % 2][1])+map[i][0];
		DP[i%2][1] = max( DP[(i - 1) % 2][2], max(DP[(i - 1) % 2][0], DP[(i - 1) % 2][1])) + map[i][1];
		DP[i%2][2] = max(DP[(i - 1) % 2][1], DP[(i - 1) % 2][2]) + map[i][2];

	}
	
	int mx=max(max(DP[(N - 1)%2][0], DP[(N - 1)%2][1]), DP[(N - 1)%2][2]);
	/*cout << "\nmax\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nmin\n";
	*/
	DP[0][0] = map[0][0];
	DP[0][1] = map[0][1];
	DP[0][2] = map[0][2];
	for (int i = 1; i < N; i++) {
		DP[i%2][0] = min(DP[(i - 1) % 2][0], DP[(i - 1) % 2][1]) + map[i][0];
		DP[i%2][1] = min(min(DP[(i - 1) % 2][0], DP[(i - 1) % 2][1]), DP[(i - 1)%2][2]) + map[i][1];
		DP[i%2][2] = min(DP[(i - 1) % 2][1], DP[(i - 1) % 2][2]) + map[i][2];
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}*/

	int mn = min(min(DP[(N - 1)%2][0], DP[(N - 1)%2][1]), DP[(N - 1)%2][2]);



	cout << mx <<" "<< mn;
	return 0;
}