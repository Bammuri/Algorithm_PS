#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int dp[1001][1001];

string LCS[1001][1001];


int main() {
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {

		for (int j = 1; j <= b.size(); j++) {


			if (a[i - 1] == b[j - 1]) {

				dp[i][j] = dp[i - 1][j - 1] + 1;
				LCS[i][j] = LCS[i][j] + LCS[i - 1][j - 1] + a[i - 1];

			}
			else {

				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				if (LCS[i - 1][j].size() > LCS[i][j - 1].size()) {
					LCS[i][j] = LCS[i - 1][j];
				}
				else {
					LCS[i][j] = LCS[i][j-1];
				}
			}

		}

	}

	cout << dp[a.size()][b.size()] << "\n";
	cout << LCS[a.size()][b.size()] << "\n";

	return 0;
}