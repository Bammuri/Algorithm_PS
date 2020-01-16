#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int K, N;
int arr[201];
int dp[201][201];


int func(int x, int y) {

	if (x==y) {
		
			return 0;

	}
	else if (x == y) {
		return 0;
	}
		
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	ret = 1987654321;
	for (int k = x; k < y; k++) {
		int tmp = arr[x] != arr[k + 1] ? 1 : 0;
		ret = min(ret, func(x, k)+func(k+1,y)+ tmp);
	}
	


	return ret;

}


int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << func(0, N - 1);

	return 0;
}