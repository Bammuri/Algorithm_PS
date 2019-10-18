#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
int n, a[11],adj[11][11],c[11],sum,ans=2e9;
int dfs(int x, int bm){
	int res = a[x];
	c[x] = 1;
	for (int i = 0; i < n; ++i){
		if (adj[x][i + 1] && (bm & (1 << i)) && !c[i + 1])
			res += dfs(i + 1, bm);

	}
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, t; i <= n; ++i){
		cin >> t;
		for (int j = 0, tmp; j < t; j++){
			cin >> tmp;
			adj[i][tmp] = 1;
		}
	}
	for (int i = 1, j; i < 1 << n; ++i){
		memset(c, 0, sizeof(c));
		sum = 0;
		for (j = 0; j < n; ++j){
			if (i&(1 << j)){
				sum = dfs(j + 1, i);
				break;
			}
		}
		//cout <<"\n"<<sum<<" ";
		for (j = 0; j < n; ++j){
			if (~i&(1 << j)){
				sum -= dfs(j + 1, ~i);
				break;
			}
		}

		//모든 노드를 방문했는지 확인
		j = 1;
		while (j <= n && c[j]) j++;
		//cout << sum << "\n";
		if (j > n){ 
			ans = min(ans, abs(sum));
			//cout << "\n " << j<<" "<<c[6] << " " << bitset<6>(i) << " " << abs(sum) << "\n";
		}
	}
	cout << (ans == 2e9 ? -1 : ans);
	return 0;
}