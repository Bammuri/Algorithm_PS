#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)

int n, m, ans = 2e9, cnt = 0;
int map[8][8];
void go(int x, int y,int depth);
vector <pair<int, int> > v;

void printmap(){
	cout << '\n';
	FOR(i, n){
		FOR(j, m)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

int check(){
	int tm = 0;
	FOR(i, n)FOR(j, m){
		if (map[i][j] == 0)tm++;
	}
	return tm;
}

void up(int x, int y){
	while (x >= 0){
		if (map[x][y] > 0 && map[x][y] < 6){
			x--; continue;
		}
		else if (map[x][y] == 6)break;
		map[x][y] = -1;
		x--;
	}
}

void down(int x, int y){
	while (x < n){
		if (map[x][y] > 0 && map[x][y] < 6){
			x++; continue;
		}
		else if (map[x][y] == 6)break;
		map[x][y] = -1;
		x++;
	}
}

void right(int x, int y){
	while (y < m){
		if (map[x][y] > 0 && map[x][y] < 6){
			y++; continue;
		}
		else if (map[x][y] == 6)break;
		map[x][y] = -1;
		y++;
	}
}

void left(int x, int y){
	while (y >= 0){
		if (map[x][y] > 0 && map[x][y] < 6){
			y--; continue;
		}
		else if (map[x][y] == 6)break;
		map[x][y] = -1;
		y--;
	}
}

void dfs(int x, int y, int depth) {
	if (depth == v.size()){
		//printmap();
		ans = min(ans, check()); return;
	}

	go(x, y, depth);

}

void go(int i, int j,int depth){
	int  tmap[8][8];
	int x = depth + 1; int y = depth + 1;
	if (depth + 1 == v.size()){
		int x = depth ; int y = depth;
	}
	switch (map[i][j]){
	case 1:
		memcpy(tmap, map, sizeof(map));
		up(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		right(i, j);  dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		left(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		down(i, j); dfs(v[x].first, v[y].second, depth + 1);
		return;
	case 2:
		memcpy(tmap, map, sizeof(map));
		up(i, j); down(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		right(i, j); left(i, j); dfs(v[x].first, v[y].second, depth + 1);
		return;
	case 3:
		memcpy(tmap, map, sizeof(map));
		up(i, j); right(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		right(i, j); down(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		down(i, j); left(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		left(i, j); up(i, j); dfs(v[x].first, v[y].second, depth + 1);
		return;
	case 4:
		memcpy(tmap, map, sizeof(map));
		up(i, j); right(i, j); left(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		right(i, j); down(i, j); up(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		down(i, j); left(i, j); right(i, j); dfs(v[x].first, v[y].second, depth + 1);
		memcpy(map, tmap, sizeof(map));

		left(i, j); up(i, j); down(i, j); dfs(v[x].first, v[y].second, depth + 1);
		return;
	case 5:
		up(i, j); right(i, j); left(i, j); down(i, j); dfs(v[x].first, v[y].second, depth + 1);
		return;
	}
}
void solve(){

	dfs(v[0].first, v[0].second, 0);

	cout << ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	FOR(i, n)FOR(j, m){
		cin >> map[i][j];
		if (map[i][j] > 0 && map[i][j] < 6)v.push_back(make_pair(i, j));
	}

	if (v.size() == 0){
		cout << check(); return 0;
	} else solve();

	return 0;
}