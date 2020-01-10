#include <iostream>
#include <algorithm>
using namespace std;
long long T, n, m,ans;
int arr1[1001], arr2[1001];
long long L[1000002];

int main() {
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}


	int idx = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr1[j];
			L[idx++] = sum;
		}
	}

	sort(L, L + idx);
	//cout << "\n";
	//for (int i=0;i<idx;i++) {
	///	cout << L[i] << " ";
	//}
	//cout << "\n";
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum += arr2[j];
			long long *low = lower_bound(L, L + idx , T - sum);
			long long *upp = upper_bound(L, L + idx, T - sum);
			//cout << ans << " " << *b - *a + 1 << " " << T - sum << "\n";
			if (low<L+idx&&*low==T-sum) {
				ans += upp - low;
				//cout << ans << " " << b - a  << " " << T - sum << "\n";
			}

		}
	}

	cout << ans;

	return 0;
}