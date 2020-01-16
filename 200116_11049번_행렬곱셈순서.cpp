#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct mat {
	int r, c;
};
mat m[501];
int dp[501][501];
int n, i;

int func(int x, int y) {
	if (x == y)
		return 0;

	int &ret = dp[x][y];
	if (ret != -1)
		return ret;

	int mm = 1987654321;

	for (int k = x; k < y; k++)
		mm = min(mm, func(x, k) + func(k + 1, y) + m[x].r*m[k].c*m[y].c);

	return ret = mm;

}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> m[i].r >> m[i].c;

	memset(dp, -1, sizeof(dp));

	cout << func(0, n - 1);

	return 0;

}