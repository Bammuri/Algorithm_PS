#include <iostream>
using namespace std;
int map[15][15];
int N,answer=0;
int v1[30], v2[30], v3[30];

void dfs(int depth) {

	if (depth == N) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (v1[i] || v2[i + depth] || v3[depth - i + N - 1]) continue;
		v1[i] = 1;
		v2[i + depth] = 1;
		v3[depth - i + N - 1] = 1;
		dfs(depth + 1);
		v1[i] = 0;
		v2[i + depth] = 0;
		v3[depth - i + N - 1] = 0;

	}
	


}


int main() {
	cin >> N;

	dfs(0);

	cout << answer;

	return 0;
}