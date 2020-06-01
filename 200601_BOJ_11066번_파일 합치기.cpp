#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int dp[501][501];
int sum[501];
int cost[501];

int dpf(int s,int e)
{	
	if (dp[s][e] != 0x2f2f2f2f)
		return dp[s][e];
	if (s == e)
		return dp[s][e] =0;
	if (s + 1 == e)
		return cost[s] + cost[e];

	for (int m = s; m < e; m++){
		int left = dpf(s, m);
		int right = dpf(m + 1, e);
		dp[s][e] = min(dp[s][e], left + right);
	}

	return dp[s][e] += sum[e] - sum[s - 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	while (T--){
		memset(dp, 0x2f, sizeof(dp));
		int K;
		cin >> K;

		for (int i = 1; i <= K; i++){
			cin >> cost[i];

			sum[i] = sum[i - 1] + cost[i];
		}
		cout << dpf(1,K)<<"\n";
	}
	return 0;
}