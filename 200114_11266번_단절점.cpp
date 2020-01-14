#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int V, E;
int a, b;
vector<int> vtx[10001],ans;
int low[10001], order[10001], parent[10001],o=1;
int selected[10001];


void dfs(int v) {
	order[v] = o++ ;
	low[v] = order[v];
	int sub = 0;
	for (int k : vtx[v]) {
		///cout << k;
		if (k == parent[v]) continue;
		//cout << v<<" "<<k<<"\n";

		if (!order[k]) {
			//cout << v << " " << k << "\n";
			parent[k] = v;
			sub++;
			dfs(k);
			if (!parent[v] && sub > 1) ans.push_back(v);
			else if (parent[v] && low[k] >= order[v]) ans.push_back(v);

			low[v] = min(low[v], low[k]);
		}
		else
			low[v] = min(low[v], order[k]);

	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b;

		vtx[a].push_back(b);
		vtx[b].push_back(a);
	}


	for (int i = 1; i <= V; i++) {
		if(!order[i])
			dfs(i);
	}

	sort(ans.begin(),ans.end());
	cout << ans.size()<<"\n";
	for (int i : ans) {
		cout << i << " ";
	}
	/*cout << "\n";
	for (int i = 1; i <= V; i++) {
		cout << order[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= V; i++) {
		cout << low[i] << " ";
	}*/
	

	return 0;
}