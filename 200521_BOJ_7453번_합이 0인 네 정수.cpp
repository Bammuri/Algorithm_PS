#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int A[4000], B[4000], C[4000], D[4000];
vector <int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];


	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			vec.push_back(A[i] + B[j]);
		}
	}

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){

			long long tmp = C[i] + D[j];

			int start = lower_bound(vec.begin(), vec.end(), -tmp) - vec.begin();
			int end = upper_bound(vec.begin(), vec.end(), -tmp) - vec.begin();
			if (start != end)
				ans += (end - start);
			else
				cout << start << "\n ";
		}
	}

	cout << ans;

	return 0;
}