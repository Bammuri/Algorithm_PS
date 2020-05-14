//1318
//1358 초안완성
//1415 TC AC 시간초과
//1505 AC 전반적인 전략 수정
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[50][50],tmap[50][50];
int n, m;
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
int idx_visit[10];
int bfs_visit[50][50];
int ans = 1e9;

typedef struct lo{
	int x, y;
}lo;

vector<lo> vec;
vector<int> idx_vec;


int spread_check(){
	int mx = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (map[i][j])continue;
			if (map[i][j] == 0 && !tmap[i][j])return -1;
			if (tmap[i][j] >mx)
				mx = tmap[i][j];
		}
	}
	return mx;
}
void print_map(){
	cout << "\n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){

			cout << tmap[i][j] << " ";
		}
		cout << "\n";
	}

}

void bfs(queue<lo> &q){

	int time = 0;
	//print_map();
	while (!q.empty()){
		int s = q.size();
		if (s > 0)
			time++;
		while (s--){
			int x = q.front().x;
			int y = q.front().y;

			q.pop();

			for (int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || bfs_visit[nx][ny] || (map[nx][ny] != 2 && map[nx][ny] != 0))continue;
				bfs_visit[nx][ny] = 1;
				tmap[nx][ny] = time;
				q.push({ nx, ny });
			}

		}

	}

	//print_map();
	int mx = spread_check();
	if (mx !=-1 && ans > mx){
		ans = mx;
		return;
	}

}

void dfs(int depth,int idx_start){

	if (depth == m){
		memset(tmap, 0, sizeof(map));
		memset(bfs_visit, 0, sizeof(map));
		queue <lo> q;
		for (int i = 0; i < idx_vec.size(); i++){
			q.push({ vec[idx_vec[i]].x, vec[idx_vec[i]].y });
			bfs_visit[vec[idx_vec[i]].x][vec[idx_vec[i]].y] = 1;
			//cout << vec[i].x << " " << vec[i].y << "\n";
		}

		bfs(q);
		return;
	}


	for (int i = idx_start; i < vec.size(); i++){
		if (idx_visit[i]) continue;
		idx_visit[i] = 1;
		idx_vec.push_back(i);
		dfs(depth + 1, i + 1);
		idx_vec.pop_back();
		idx_visit[i] = 0;

	}

}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
			if (map[i][j] == 2){
				vec.push_back({ i, j });
			}
		}
	}


	dfs(0,0);

	if (ans != 1e9)
		cout << ans;
	else
		cout << -1;

	return 0;
}