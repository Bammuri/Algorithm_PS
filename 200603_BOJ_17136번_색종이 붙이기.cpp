#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int map[10][10];
int checkcnt[6];
int ans = INF;

bool is_and(vector< vector<int> > &map)
{
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (map[i][j] == 1) { return false; }
		}
	}
	return true;
}

void get_next_xy(vector< vector<int> > &map,int &x,int &y)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) { x = i; y = j; return; }
		}
	}
}

void dfs(int d, int r, int c, int size, vector< vector<int> > map) {
	
	if (d > ans) return;
	if (r + size > 10 || c + size > 10)return;

	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] == 0) return;
			map[i][j] = 0;
		}
	}

	if (is_and(map)){
		ans = ans > d ? d : ans;
		return;
	}

	int x, y;
	get_next_xy(map, x, y);

	for (int i = 5; i >= 1; i--) {
		if (checkcnt[i] == 5) continue;
		checkcnt[i]++;
		dfs(d + 1, x, y, i, map);
		checkcnt[i]--;
	}
}

int main(void) {
	std::vector< std::vector<int> > map(10, vector<int>(10, 0));
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	dfs(0, 0, 0, 0, map);

	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}
