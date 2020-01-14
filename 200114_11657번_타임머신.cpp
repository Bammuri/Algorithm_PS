#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define INF 1987654321
using namespace std;



struct edge {
	int to, val;
};

int V, E, A, B, C, D[501];
vector <edge> adj[501];
deque <edge> dq;


int BellmanFord(int exe) {
	int t = V - 1;
	while (t--) {
		/*cout << t << "\n";
		for (int i = 1; i <= V; i++)
		if (D[i] != INF)
		cout << D[i] << " ";
		else
		cout << "INF";
		cout << "\n";*/
		for (int i = 1; i <= V; i++) {
			for (int k = 0; k < adj[i].size(); k++) {

				int dst = adj[i][k].to;
				int pval = adj[i][k].val;

				int nval = D[i] + pval;

				if (nval < D[dst] && D[i] != INF) {

					if (exe) return 1;
					D[dst] = nval;
				}

			}
		}

	}


	return 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 2; i <= V; i++) {
		D[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		adj[A].push_back({ B,C });

	}




	BellmanFord(0);

	if (BellmanFord(1)) {
		cout << "-1";
	}
	else {
		for (int i = 2; i <= V; i++)
			if (D[i] != INF)
				cout << D[i] << "\n";
			else
				cout << -1 << "\n";
	}

	return 0;
}