//1000ms 이상 나오는 코드
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
	if (cnt > 3 || cnt >= ans) return;
	if (do_game()){
		ans = Min(ans, cnt);
		return;
	}
	for (int j = 1; j < n; j++){
		for (int i = idx; i <= h; i++){
			if (map[i][j])continue;
			if (map[i][j + 1])continue;
			if (map[i][j - 1])continue;
			map[i][j] = 1;
			dfs_secline(i, cnt + 1);
			map[i][j] = 0;
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
///0ms 나오는 코
#include <iostream>
#include <string.h>
using namespace std;
int N, M, H;
int min_line = 4;
int map[32][11];
bool check_ladder(int depth){
	for (int i = 1; i <= N; i++){
		int r = 1;
		int c = i;

		while (1){
			if (r == H + 1) break;

			if (map[r][c] == 1){
				c++;
			}
			else if (map[r][c - 1] == 1){
				c--;
			}
			r++;
		}
		if (c != i) return false;
	}
	min_line = min(min_line, depth);
	return true;
}
void find_path(int depth){
	if (min_line <= depth) return;
	if (check_ladder(depth)){
		return;
	}
	if (depth >= 3) return;

	for (int c = 1; c<N; c++){
		for (int r = 1; r <= H; r++){
			if (map[r][c] == 1) continue;
			if (map[r][c - 1] == 1 || map[r][c + 1] == 1) continue;

			map[r][c] = 1;
			find_path(depth + 1);
			map[r][c] = 0;

			while (1){
				if (r >= H) break;
				if (map[r + 1][c - 1] || map[r + 1][c + 1]) break;
				r++;
			}

		}
	}
	return;
}
int main(int argc, const char * argv[]) {
	scanf("%d %d %d", &N, &M, &H);
	int a, b;
	for (int i = 0; i<M; i++){
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	if (M == 0){
		min_line = 0;
		printf("%d", min_line);
		return 0;
	}

	find_path(0);

	if (min_line == 4) min_line = -1;
	printf("%d\n", min_line);
	return 0;
}
