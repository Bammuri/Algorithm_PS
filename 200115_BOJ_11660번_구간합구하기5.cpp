#include <iostream>
using namespace std;

int ans[1025][1025], num;
int N, M, xx1, xx2, yy1, yy2;


void print() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			cout << ans[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int s = 0;
		for (int j = 1; j <= N; j++) {
			cin >> num;
			s += num;
			int ns = s;
			
			ns += ans[i-1][j];

			
			ans[i][j] = ns;

		}
	}

	//print();


	int t = M;
	while (t--) {
		cin >> xx1 >> yy1 >> xx2 >> yy2;
		
		cout << ans[xx2][yy2 ] - (ans[xx2][yy1 - 1] + ans[xx1 - 1][yy2])+ans[xx1-1][yy1-1]<<"\n";
		

	}

	return 0;
}