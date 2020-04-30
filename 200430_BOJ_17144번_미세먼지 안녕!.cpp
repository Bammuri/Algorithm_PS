// 1657 Ω√¿€
// 1745 AC 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int R, C, T;
int map[50][50],tmap[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

typedef struct lo{
	int x, y;
}lo;

vector <lo> aircon;

void printmap(){
	cout << "\n";
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout<<map[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void spread_unit(int x,int y){
	int cnt = 0;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == -1)continue;
		tmap[nx][ny] += map[x][y] / 5;
		cnt++;
	}
	tmap[x][y] += map[x][y] - ((map[x][y] / 5) * cnt);

}

void spread(){
	memset(tmap, 0, sizeof(tmap));
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] && map[i][j] != -1){
				tmap[aircon[0].x][aircon[0].y] = -1;
				tmap[aircon[1].x][aircon[1].y] = -1;
				spread_unit(i, j);
			}
		}
	}
	memcpy(map, tmap, sizeof(tmap));
}

void aircongo(){

	int x = aircon[0].x;
	int y = aircon[0].y;
	for (int i = x - 2; i >= 0; i--)
		map[i + 1][y] = map[i][y];
	for (int i = 0; i+1 < C; i++)
		map[0][i] = map[0][i+1];
	for (int i = 0; i + 1 <= x; i++)
		map[i][C-1] = map[i+1][C-1];
	for (int i = C-1; i -1 >= 1; i--)
		map[x][i] = map[x][i - 1];
	map[x][y + 1]=0;

	x = aircon[1].x;
	y = aircon[1].y;
	for (int i = x + 1; i + 1 < R; i++)
		map[i][0] = map[i + 1][0];
	for (int i = 0; i + 1 < C; i++)
		map[R-1][i] = map[R-1][i + 1];
	for (int i = R - 2; i >= x; i--)
		map[i + 1][C - 1] = map[i][C -1];
	for (int i = C - 1; i - 1 >= 1; i--)
		map[x][i] = map[x][i - 1];
	map[x][y + 1] = 0;

}




int cnt(){
	int s = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] != -1 && map[i][j])
				s += map[i][j];

		}
	}


	return s;
}


int sol(){

	for (int i = 0; i < T; i++){

		spread();
		//printmap();
		aircongo();
		//printmap();
	}

	return cnt();

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
			if (map[i][j] == -1)
				aircon.push_back({ i, j });
			
		}
	}

	cout<<sol();

	return 0;
}