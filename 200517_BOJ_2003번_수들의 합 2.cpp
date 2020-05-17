#include <iostream>
using namespace std;

int n, m,ans;
int arr[10000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int sum = 0;
	int s = 0, e = 0;
	while (true)
	{
		if (sum < m){
			if (e != n)
				sum += arr[e++];
		}
		else
			sum -= arr[s++];

		if (sum == m)
			ans++;

		if (sum < m && e == n) break;
		//cout << " sum " << sum << " s " << s << " e " << e << "\n";

	}

	cout << ans;

	return 0;
}