#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, a, b, c,ans;
bool chk;
struct node {
	int to, from, val;
	bool operator <(const node& n) const {
		return val<n.val;
	}
};

vector<node> vn;
int parent[1001];


int find(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

void merge(int a,int b) {
	chk = false;
	int aa = find(a);
	int bb = find(b);

	if (aa == bb)
		return;

	if (aa >= bb)
		parent[aa] = parent[bb];
	else
		parent[bb] = parent[aa];
	
	chk = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vn.push_back({ a,b,c });
	}

	sort(vn.begin(), vn.end());

	for (node n : vn) {
		merge(n.to, n.from);

		if (chk)
			ans += n.val;
	}
	cout << ans;


	return 0;
}