#include <cstdio>
#include <vector>
using namespace std;
int n;
long long dp[101][11];



int main() {
	scanf_s("%d", &n);
	
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;

		}
	
	}
	
	long long ans=0;
	for (int i = 0; i < 10; i++) {
		ans+=dp[n][i];
		ans %= 1000000000;
		//printf(" %lld ", dp[n][i]);
	}
	
	printf("%lld\n", ans);
	return 0;
}