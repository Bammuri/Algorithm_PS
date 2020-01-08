#include <iostream>
using namespace std;

int a[26][2];
int N;



void preorder(int node) {
	if (node == -1)
		return;

	cout << char(node + 'A');
	preorder(a[node][0]);
	preorder(a[node][1]);

}



void midorder(int node) {
	if (node == -1)
		return;

	
	midorder(a[node][0]);
	cout << char(node + 'A');
	midorder(a[node][1]);

}

void postorder(int node) {
	if (node == -1)
		return;

	
	postorder(a[node][0]);
	postorder(a[node][1]);
	cout << char(node + 'A');
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		a[root - 'A'][0] = left != '.' ? left - 'A' :  - 1;
		a[root - 'A'][1] = right != '.' ? right - 'A' : -1;

	}


	preorder(0);
	cout << "\n";
	midorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}