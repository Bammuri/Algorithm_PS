#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
int n, ans;
int map[20][20];
//dir 0 ¿À 1 ¾Æ 2 ¿Þ 3 À§
vector <int> a;

void printm(){
	cout << "\n";
	FOR(i, 5){
		FOR(j, 5)cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int getmax(){
	int max = 0;
	FOR(i, n)FOR(j, n){
		if (max < map[i][j])max = map[i][j];
	}
	return max;
}

void move(int dir) {
	int tmap[20][20] = { 0, };
	FOR(i, n) {
		vector <int> tm;
		a.clear();
		FOR(j, n){

			switch (dir){
			case 0:
				if (map[i][n - (j + 1)] != 0)
					tm.push_back(map[i][n - (j + 1)]);
				break;
			case 1:
				if (map[n - (j + 1)][i] != 0)
					tm.push_back(map[n - (j + 1)][i]);
				break;
			case 2:
				if (map[i][j] != 0)
					tm.push_back(map[i][j]);
				break;
			case 3:
				if (map[j][i] != 0)
					tm.push_back(map[j][i]);
				break;
			}

		}
		//cout << "\n";
		//for (auto t : tm){
		//	cout << " " << t << " ";
		//}
		//cout << "\n";
		FOR(b, tm.size()){
			if (b + 1 < tm.size()){
				if (tm[b] == tm[b + 1]){
					a.push_back(tm[b] + tm[b + 1]); b++;
				}
				else
					a.push_back(tm[b]);
			}
			else {
				a.push_back(tm[b]);
			}
		}
		int c = a.size();
		//cout << "\n" << c << " " << dir << " " << n << " " << i;
		//cout << "\n" << a[0] << " " << a[1];
		switch (dir){
		case 0:
			FOR(k, c) tmap[i][n - (k + 1)] = a[k];
			break;
		case 1:
			FOR(k, c) tmap[n - (k + 1)][i] = a[k];
			break;
		case 2:
			FOR(k, c) tmap[i][k] = a[k];
			break;
		case 3:
			FOR(k, c) tmap[k][i] = a[k];
			break;
		}
	}
	memcpy(map, tmap, sizeof(tmap));
}


void dfs(int depth){
	int tmap[20][20] = { 0, };
	if (5 == depth) {
		int tmp = getmax();
		ans < tmp ? ans = tmp : ans;
		return;
	}
	memcpy(tmap, map, sizeof(map));
	FOR(k, 4){

		move(k);
		//cout << "\n" << depth << " ";
		//printm();
		if (!memcmp(map, tmap, sizeof(map))){
			int tmp = getmax();
			ans < tmp ? ans = tmp : ans;
			continue;
		}
		dfs(depth + 1);
		memcpy(map, tmap, sizeof(map));
	}
}

void solve(){

	dfs(0);

	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, n){
		FOR(j, n)cin >> map[i][j];
	}

	solve();

	return 0;
}