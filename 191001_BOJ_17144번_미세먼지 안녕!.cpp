#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,A) for(int i=0;i<A;++i)
using namespace std;

int R, C, T,ans ;
int map[50][50],tmap[50][50];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
vector <int > cleaner;


void spread(){
	memset(tmap, 0, sizeof(tmap));
	tmap[cleaner[0]][0] = -1;
	tmap[cleaner[1]][0] = -1;
	
	FOR(i, R){
		FOR(j, C){
			if (map[i][j]&&map[i][j]!=-1){
				int dust = map[i][j] / 5;
				int cnt = 0;
				FOR(k, 4) { 
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= R || nx < 0 || ny >= C || ny < 0 || map[nx][ny] == -1)continue;
					tmap[nx][ny] += dust;
					cnt++;
				}
				tmap[i][j] += map[i][j] - (dust*cnt);

			}
		}
	}
	memcpy(map, tmap, sizeof(tmap));
}


void cycling(){
	for (int i = cleaner[0] - 2; i >= 0; i--)
		map[i + 1][0] = map[i][0];
	
	for (int i = 1; i < C; i++)
		map[0][i - 1] = map[0][i];

	for (int i = 1; i <= cleaner[0]; i++)
		map[i - 1][C-1] = map[i][C-1];

	for (int i = C-2; i >= 1; i--)
		map[cleaner[0]][i+1] = map[cleaner[0]][i];

	map[cleaner[0]][1] = 0;

	for (int i = cleaner[1] + 2; i < R; i++)
		map[i - 1][0] = map[i][0];

	for (int i = 1; i < C; i++)
		map[R-1][i - 1] = map[R-1][i];

	for (int i = R-2; i >= cleaner[1]; i--)
		map[i + 1][C - 1] = map[i][C - 1];

	for (int i = C - 2; i >= 1; i--)
		map[cleaner[1]][i + 1] = map[cleaner[1]][i];

	map[cleaner[1]][1] = 0;
	
}

void getans(){
	FOR(i, R)
		FOR(j, C)
		if (map[i][j]!=-1)
			ans += map[i][j];
}
void printmap(){
	cout << "\n";
	FOR(i, R){
		FOR(j, C)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}


void solve(){
	while (T--){
		spread();
		//printmap();
		cycling();
		//printmap();
	}
	getans();
}


int main(){
	cin >> R >> C >> T;
	FOR(i, R){
		FOR(j, C){
			cin >> map[i][j];
			if (map[i][j] == -1)
				cleaner.push_back(i);
		}
	}

	solve();

	cout << ans;
	return 0;
}