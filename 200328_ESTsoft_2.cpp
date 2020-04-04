#include <algorithm>
#include <map>
#include <cstring>
int mx = 0;
int a[2], visit[200000];
map <int, vector<int>> m;


void dfs(int depth, vector<int> &A, int vsize) {

	if (depth == 2) {
		if (a[0] + a[1]>mx)
			mx = a[0] + a[1];
		return;
	}

	for (int i = 0; i < vsize; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		a[depth] = A[i];
		dfs(depth + 1, A, vsize);
		visit[i] = 0;
	}

}

int solution(vector<int> &A) {

	for (auto n : A) {
		int sum = 0;
		int num = n;
		while (n != 0) {
			sum += n % 10;
			n /= 10;
		}
		m[sum].push_back(num);
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		memset(visit, 0, sizeof(visit));
		int vsize = it->second.size();
		if (vsize < 2) continue;
		dfs(0, it->second, vsize);
	}
	if (mx == 0)
		return (-1);
	return (mx);
}