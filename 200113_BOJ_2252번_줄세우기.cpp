#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n, m,a,b;

vector<vector<int>> adlist(35000);
int vc[35000];
deque <int> q;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		adlist[b].push_back(a);
		vc[a]++;
	}

	for (int i = 1; i <= n; i++) {
		if (vc[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		int g = pq.top();
		pq.pop();
		q.push_front(g);
		for (int a : adlist[g]) {
			vc[a] -= 1;
			if (vc[a] == 0)
				pq.push(a);
		}
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop_front();
	}


	return 0;
}