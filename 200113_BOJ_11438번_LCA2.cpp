#include <iostream>
#include <vector>
#include <cmath>
#define MAX_NODE 100001 

using namespace std;
int n, m;
int a, b;

int depth[MAX_NODE];
int ac[MAX_NODE][20];

int max_level;
vector<int> graph[MAX_NODE];

void make_tree(int here, int parent) {
	depth[here] = depth[parent] + 1;


	ac[here][0] = parent;

	max_level = (int)floor(log2(MAX_NODE));

	for (int i = 1; i <= max_level; i++) {
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}

	int len = graph[here].size();
	for (int i = 0; i < len; i++) {
		int there = graph[here][i];
		if (there != parent)
			make_tree(there, here);
	}


}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n-1; i++) {

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	depth[0] = -1;

	make_tree(1, 0);

	cin >> m;

	for (int k = 0; k < m; k++) {
		cin >> a >> b;

		if (depth[a] != depth[b]) {

			if (depth[a] > depth[b]) {
				int tmp = a; a = b; b = tmp;
			}

			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}

		int lca = a;

		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		cout << lca<<"\n";

	}

	return 0;
}