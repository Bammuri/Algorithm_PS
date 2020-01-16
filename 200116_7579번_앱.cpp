#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, dp[100][10001], m[101], c[101];



int MakeBig(int idx, int totalCost) {

	if (idx >= N)
		return 0;


	int &ret = dp[idx][totalCost];

	if (ret != -1) 
		return ret;

	ret = MakeBig(idx + 1, totalCost);

	if (c[idx] <= totalCost)
		ret = max(ret, m[idx] + MakeBig(idx+1,totalCost - c[idx]));


	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		cin >> m[i];
	
	for (int i = 0; i < N; i++) 
		cin >> c[i];
	
	memset(dp, -1, sizeof(dp));

	int totalCost = 0;
	//cout << totalCost;
	while (1) {

		if (MakeBig(0, totalCost) >= M) {
			cout << totalCost;
			break;
		}
		//cout << totalCost;
		totalCost++;
	}



	return 0;
}