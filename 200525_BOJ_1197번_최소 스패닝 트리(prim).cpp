#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXV 10001

int V, E, ans;
vector<pair<int, int> >adj[MAXV];
int vertexVisit[MAXV];

typedef struct Ver{
	int node, val;
	bool operator <(const Ver &o)const{
		return val < o.val;
	}
};


int sol()
{
	priority_queue <Ver> pq;
	pq.push({ 1,0 });

	while (!pq.empty())
	{
		int cur = pq.top().node;
		int v = -pq.top().val;
		pq.pop();

		if (vertexVisit[cur])continue;
		vertexVisit[cur] = 1;
		ans += v;
		
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first;
			int val = adj[cur][i].second;
			if (vertexVisit[next])continue;
			pq.push({ next, -val });
		}

	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	cout << sol();
	return 0;
}