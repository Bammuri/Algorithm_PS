#include <iostream>
using namespace std;
int n, m;
int a, b, c;
int parent[1000001];



int getp(int k) {
	if (parent[k] == k)
		return k;

	return parent[k]=getp(parent[k]);
}

void un(int a,int b) {
	int aa = getp(a);
	int bb = getp(b);

	
	if (aa >= bb)
		parent[bb] = getp(aa);
	else
		parent[aa] = getp(bb);
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= 1000001; i++) 
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			if (getp(b) == getp(c))
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else {
			un(b, c);
		}


	}

	return 0;
}