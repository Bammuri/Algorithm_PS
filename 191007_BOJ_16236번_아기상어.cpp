#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

int map[20][20], dis[20][20];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };


typedef struct shark{
	int x, y;
	int size = 2;
	int cnt = 0;
}S;

typedef struct fish{
	int x, y, dis;
	bool operator <(const fish& f)const{
		if (dis == f.dis && x == f.x) return y < f.y;
		if (dis == f.dis) return x < f.x;
		return dis < f.dis;
	}
};

S shark;
int n, ans;
vector <fish> fishes;
fish target;

bool OOR(int x, int y){
	return x < 0 || x >= n || y < 0 || y >= n;
}


int getfish(){
	memset(dis, -1, sizeof(dis));
	queue<pair<int, int> > q;
	int x = shark.x, y = shark.y;
	q.push(make_pair(x, y));
	dis[x][y] = 0;
	while (!q.empty()){
		int x = q.front().first, y = q.front().second;	q.pop();
		FOR(i, 4){
			int nx = x + dx[i], ny = y + dy[i];
			if (OOR(nx, ny) || shark.size < map[nx][ny] || dis[nx][ny] != -1)continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	fishes.clear();

	FOR(i, n)FOR(j, n){
		if (map[i][j] >0 && shark.size>map[i][j] &&dis[i][j]!=-1){
			fishes.push_back({ i, j, dis[i][j] });
		}
	}
	return fishes.size();

}

void eat(){
	ans += target.dis;
	shark.x = target.x, shark.y = target.y;
	map[shark.x][shark.y] = 0;

	shark.cnt++;
	if (shark.cnt == shark.size){
		shark.cnt = 0;
		shark.size++;
	}
}

void getclose(){
	sort(fishes.begin(), fishes.end());
	target = fishes[0];
}


void solve(){

	while (1){
		int fish_cnt = getfish();
		//cout << fish_cnt << "\n";
		if (fish_cnt == 0){
			break;
		}
		else if (fish_cnt == 1) {
			target = fishes[0];
			eat();
		}
		else {
			getclose();
			eat();
		}
	}
}


int main(){
	cin >> n;

	FOR(i, n)FOR(j, n){
		cin >> map[i][j];
		if (map[i][j] == 9){
			map[i][j] = 0;
			shark.x = i, shark.y = j;
		}
	}

	solve();

	cout << ans;

	return 0;
}