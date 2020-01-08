#include <iostream>

using namespace std;

long long N, M, mx, answer, mn = 0, mm, gmn = 1987654321;
int tree[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (mx < tree[i])
			mx = tree[i];

	}

	int st = (mx + mn) / 2;

	while (1) {
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		int g = tree[i] - st;
		if (g > 0)
			sum += g;
	}

	//cout << st << " " << sum << "\n";

	if (sum - M >= 0) {
		if (gmn == sum - M||sum-M==0) {
			answer = st;
			break;
		}
		gmn = sum - M;
	}

	if (sum > M) {
		mn = st + 1;
	}
	else {
		mx = st - 1;
	}
	st = (mx + mn) / 2;

	}
	
	cout << answer;
	return 0;
}
