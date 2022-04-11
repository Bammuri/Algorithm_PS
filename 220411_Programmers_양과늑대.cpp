#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool adj[17][17];
int cache[17][(1 << 17) - 1]; // bitmasking memoization

int solve(int n, int visited, vector<int>& info) {
	int& ret = cache[n][visited];
	if (ret != -1) return ret;

	int sheep = 0, wolf = 0;
	for (int i = 0; i < 17; i++) {
		if (visited & (1 << i)) {
			if (info[i]) wolf++;
			else sheep++;
		}
	}

	if (sheep == wolf) return ret = 0; // 양이 잡하먹히므로 진행 불가

	ret = sheep;
	for (int i = 0; i < 17; i++) {
		if (!adj[n][i]) continue;
		ret = max(ret, solve(i, visited | (1 << i), info));
	}

	return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	for (auto v : edges) adj[v[0]][v[1]] = adj[v[1]][v[0]] = true;
	memset(cache, -1, sizeof(cache));
	return solve(0, 1, info);
}

int main() {
	vector<int> info = {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1};
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}};
	cout<<solution(info, edges);
	return 0;
}