#include <iostream>
#include <queue>
#include <functional>

using namespace std;
typedef struct edge
{
	int f, s, val;
	bool operator < (const edge &o)const{
		return val > o.val;
	}
};

priority_queue<edge, vector<edge> > pq;
int V, E,ans,parent[10001];
int find(int x)
{
	if (!parent[x]) return x;

	return parent[x] = find(parent[x]);
}


bool merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v) return false;

	parent[u] = v;
	return true;
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
		pq.push({ a, b, c });
	}
	
	while (!pq.empty())
	{
		edge t = pq.top();
		pq.pop();
		if (merge(t.f, t.s)) ans += t.val;

	}
	cout << ans;
	return 0;
}