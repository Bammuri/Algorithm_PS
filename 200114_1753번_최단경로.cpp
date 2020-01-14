#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define INF 1987654321
using namespace std;
struct edge {
	int to, val;
	bool operator< (const edge &e)const {
		return val > e.val;
	}
};
int V, E;
int K,D[20001];
vector<edge> adj[20001];
priority_queue <edge> pq;
int from;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	cin >> K;

	for (int i = 1; i <= V; i++) {
		if(i!=K)
			D[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		
		edge a;
		cin >> from >> a.to >> a.val;
		adj[from].push_back(a);
	}

	pq.push({ K,0 });


	while (!pq.empty()) {
		edge e= pq.top();
		pq.pop();


		for (edge a : adj[e.to]) {

			if (D[a.to] > a.val+e.val) {
				D[a.to] = a.val+e.val;
				pq.push({a.to,a.val+e.val});
			}
		}
		

	}

	for (int i = 1; i <= V; i++) {
		if (D[i] == 1987654321)
			cout << "INF\n";
		else
			cout <<D[i] << "\n";
	}

	return 0;
}