//1724시작
//1806 테케 다맞음 but 틀림
//벽 copy이슈
//1830 해결
//
//
/*
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
char map[8][8],dmap[8][8];
int px,py;

//dir 오른쪽 시작 시계방향
int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[9] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 };

int bfs(){
	queue <pair<int, int> >q;
	q.push(make_pair(px, py));

	while (!q.empty()){
		int n = q.size();
		while (n--){
			//cout << '\n';
			int x = q.front().first;
			int y = q.front().second;
			
			q.pop();
			if (map[x][y] == '#')continue;
			
			if (x == 0 && y == 7)return 1;

			FOR(i, 9){
				int nx = x + dx[i]; int ny = y + dy[i];
				if (nx<0||nx>=8||ny<0||ny>=8||map[nx][ny] != '.')continue;
				q.push(make_pair(nx, ny));
				//cout << '\n' << nx << " " << ny << '\n';
			}

		}

		char tmap[8][8];

		memcpy(tmap, dmap, sizeof(map));

		FOR(i, 8)FOR(j, 8){
			
			if (map[i][j] == '#'){
				if (i < 7){
					tmap[i+1][j] = '#';
				}
			}
		}
		memcpy(map, tmap, sizeof(map));


	}
	return 0;
}

void solve(){

	cout << bfs();


}

int main(){
	memset(map, 0, sizeof(map));
	px = 7, py = 0;
	FOR(i, 8){
		cin >> map[i];
		FOR(j, 8) dmap[i][j] = '.';
	}
	solve();

	return 0;
}
*/

// 7번만 지나면 무조건 벽이 없기 때문에 무조건 통과
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

char map[8][8][9];
int res = 0;
int dx[9] = { 0, 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[9] = { 0, 1, -1, 0, 0, 1, -1, 1, -1 };
void dfs(int x, int y, int t)
{
	int X, Y;
	if (t == 7)
	{
		res = 1;
		return;
	}
	for (int d = 0; d < 9; d++)
	{
		X = x + dx[d];
		Y = y + dy[d];
		if (X < 0 || Y < 0 || X >= 8 || Y >= 8) continue;
		if (map[t][X][Y] == '#' || map[t + 1][X][Y] == '#') continue;
		dfs(X, Y, t + 1);
	}
}

int main() {
	for (int i = 0; i < 8; i++)
		scanf("%s", map[0][i]);

	//통나무 이동 미리 계산
	for (int i = 1; i < 8; i++)
	{
		for (int a = 0; a < 8; a++)
		{
			for (int b = 7; b > 0; b--)
				map[i][b][a] = map[i - 1][b - 1][a];
			map[i][0][a] = '.';
		}
	}
	dfs(7, 0, 0);
	printf("%d\n", res);
	return 0;
}