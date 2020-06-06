//0955¿Ï¼º
//1007AC 37ºÐ
#include <iostream>
#include <cstring>
using namespace std;

int N, M, ans;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int map[50][50];

typedef struct ro{
	int x, y, dir;
};

ro robo;

void print_map()
{
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout<< map[i][j]<<" ";
		}
		cout << "\n";
	}
}

bool algo(int x, int y, int dir)
{
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		dir -= 1;
		if (dir == -1)dir = 3;

		nx = x + dx[dir];
		ny = y + dy[dir];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (map[nx][ny] != 0) continue;

		robo.x = nx;
		robo.y = ny;
		robo.dir = dir;
		return false;
	}
	nx = x + dx[(robo.dir + 2) % 4];
	ny = y + dy[(robo.dir + 2) % 4];
	if (map[nx][ny] == 1){
		return true;
	}

	robo.x = nx;
	robo.y = ny;
	return false;
}

void sol()
{

	while (true)
	{
		int x = robo.x;
		int y = robo.y;
		int dir = robo.dir;
		//cout << x << " " << y << " " << dir << "\n";
		if (map[x][y] != 2){
			ans++;
			map[x][y] = 2;
		}
		//print_map();
		
		if (algo(x, y, dir))
			return;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//memset(map, 0, sizeof(map));

	cin >> N >> M;

	cin >> robo.x >> robo.y >> robo.dir;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	sol();
	cout << ans;

	return 0;
}