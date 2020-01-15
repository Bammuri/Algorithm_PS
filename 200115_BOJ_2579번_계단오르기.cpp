# include <iostream>
# include <algorithm>
using namespace std;

int s[301],n,ans[301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; 
	}
	ans[1] = s[1];
	ans[2] = s[2]+ s[1];

	for (int i = 0; i <= n-3; i++) {
		ans[i + 3] = max(s[i + 3] + ans[i+1], s[i + 3] + s[i + 2] + ans[i]);
	}

	
	cout << ans[n] << " ";
	

	return 0;
}