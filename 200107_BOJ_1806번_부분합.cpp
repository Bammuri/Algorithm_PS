#include <iostream>
using namespace std;

int arr[100000], N, S, ans = 1987654321;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int sum = 0;
	int j = 0;
	for (int i = 0; i < N; i++) {
		for (; j < N; j++) {
			sum += arr[j];
			//cout << i << " " << j << " " << sum << "\n";
			if (sum >= S) {
				if (ans > j - i + 1) ans = j - i + 1;
				sum -= arr[j];
				break;
			}
		}
		sum -= arr[i];
	}
	if (ans == 1987654321)
		cout << "0";
	else
		cout << ans;
	return 0;
}