#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int n, m,ma[1001][1001],ans;
string map[1001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m; j++) {
			ma[i][j] = map[i-1][j-1] - '0';
			
			if (ma[i][j] == 1) {
				ma[i][j] = min(min(ma[i-1][j], ma[i][j-1]), ma[i-1][j-1])+1;

				if (ans < ma[i][j])
					ans = ma[i][j];
			}

			
		}
		//cout << "\n";
	}
	cout << ans*ans;

	return 0;
}