#include <iostream>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int map[32][12];
int n, m, h, ans;

int Min(int A, int B) { if (A < B) return A; return B; }

bool do_game(){

	for (int start = 1; start <= n; start++) {

		int current_num = start;

		for (int i = 1; i <= h; i++){
			if (map[i][current_num])current_num++;
			else if (map[i][current_num - 1])current_num--;
		}

		if (current_num != start) return false;
	}
	return true;
}


void dfs_secline(int idx, int cnt){

	if ( cnt >= ans) return;

	if (do_game()){
		ans = Min(ans, cnt);
		return;
	}
	if (cnt >= 3 )return;

	for (int j = 1; j < n; j++){
		for (int i = idx; i <= h; i++){
			if (map[i][j])continue;
			if (map[i][j + 1])continue;
			if (map[i][j - 1])continue;

			map[i][j] = 1;
			dfs_secline(i, cnt + 1);
			map[i][j] = 0;


			// 다음 다리가 나타나기 전까지 다리를 놓는건 의미없음 , 같은 결과
			while (1){
				if (i>= h) break;
				if (map[i + 1][j - 1] || map[i + 1][j + 1]) break;
				i++;
			}

		}
	}
}

void solve(){

	dfs_secline(1, 0);

	if (ans == 4)ans = -1;

	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ans = 4;
	cin >> n >> m >> h;

	FOR(i, m){
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}


	solve();

	return 0;
}