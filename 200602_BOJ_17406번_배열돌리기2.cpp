#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, K;

int map[50][50], omap[50][50];

typedef struct unit{
	int r, c, s;
};

vector <unit> vec;
int order[6], visit[6];
int ans = 1e9;
int dx[] = { 1,0 ,-1,0};
int dy[] = { 0, 1,0,-1};

void print_map(){
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}


void rotate(int r, int c, int ts){
	int s = 1;

	while (s <= ts){

		int dir = 0;
		int x = r - s;
		int y = c - s;
		int nx = x;
		int ny = y;
		int tmp = map[x][y];
		while (1){
			nx += dx[dir];
			ny += dy[dir];
			if (nx < r - s || nx > r + s || ny > c + s || ny < c - s){
				nx -= dx[dir];
				ny -= dy[dir];
				dir = (dir + 1) % 4;
				continue;
			}
			if (nx == r - s && ny == c - s){ map[x][y] = tmp; break; }
			map[x][y] = map[nx][ny];
			x = nx;
			y = ny;

		}
		
		s++;
	}

}

int getAMin(){
	int tans = 1e9;
	for (int i = 0; i < N; i++){
		int tmp = 0;
		for (int j = 0; j < M; j++){
			tmp += map[i][j];
		}
		if (tans > tmp)
			tans = tmp;
	}
	return tans;
}

void dfs(int d){
	if (d == vec.size()){
		memcpy(map, omap, sizeof(map));

		for (int i = 0; i < d; i++){
			rotate(vec[order[i]].r, vec[order[i]].c, vec[order[i]].s);
		}
		int t = getAMin();
		if (ans > t)
			ans = t;
	}


	for (int i = 0; i < vec.size(); i++){
		if (visit[i]) continue;
		visit[i] = 1;
		order[d] = i;
		dfs(d + 1);
		visit[i] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> omap[i][j];
		}
	}

	for (int i = 0; i < K; i++){
		int r, c, s;
		cin >> r >> c >> s;
		vec.push_back({ r-1, c-1, s });
	}

	dfs(0);


	cout << ans;

	return 0;
}