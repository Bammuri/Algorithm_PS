#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9

typedef struct lo{
	int dst, val;
	bool operator < (const lo &o)const {
		return val < o.val;
	}
};

int V, E,K;
vector <lo> edge[20000];
vector <int> ans;
priority_queue<lo> pq;


void sol(int startNode)
{
	pq.push({ startNode - 1, 0 });
	ans[startNode - 1] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().dst;
		int val = -pq.top().val;
		pq.pop();

		if (ans[cur] < val) continue;

		for (lo t : edge[cur]){

			int nxt = t.dst;
			int nxtVal = ans[cur] + t.val;
			if (nxtVal < ans[nxt]){
				ans[nxt] = nxtVal;
				pq.push({ nxt, -nxtVal });
			}

		}
	}

	for (int i = 0; i < V; i++)
		if (ans[i] == INF) cout << "INF\n";
		else cout << ans[i] << "\n";
	

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V >> E >> K;
	ans.resize(V,INF);
	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		edge[from - 1].push_back({ to-1, val });
	}

	sol(K);

	return 0;
}