#include <iostream>
using namespace std;

int N, M, k;
int u, v;
int val[10001];
int root[10001];


int find(int v){
	if (!root[v])
		return v;

	return root[v] = find(root[v]);
}


void merge(int v, int u){
	v = find(v);
	u = find(u);

	if (v != u){
		if (val[v] > val[u])
			root[v] = u;
		else
			root[u] = v;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
		cin >> val[i];

	for (int i = 0; i < M; i++){
		cin >> u >> v;
		merge(u, v);
	}
	//cout << "what";
	int sum = 0;
	for (int i = 1; i <= N; i++){
		//cout <<i ;
		if (find(i) == i)sum += val[i];
		if (sum > k){ cout << "Oh no"; return 0; }
	}

	cout << sum;

	return 0;
}