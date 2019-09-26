#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, maxm,minm=1987654321;
int map[51][51],initcheck[51][51],check[51][51];
int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, 1, -1, 0 };
vector <pair<int, int>> virus;
int virus_idx[11];
queue <pair<int, int>> q;

void copymap(int(*a)[51], int(*b)[51]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = b[i][j];
}
int getmax(){
	maxm = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				
				if (map[i][j])continue;
				if (check[i][j] == -1)return maxm = 1987654321;
				if (maxm < check[i][j])maxm = check[i][j];
			}
		return maxm;
}

void bfs(){
	while (!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++){
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx >= N || nx < 0 || ny >= N || ny < 0)continue;
			if (check[nx][ny] != -1)continue;

			check[nx][ny] = check[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	minm=min(minm, getmax());
}

void spread(){

	for (int i = 0; i < virus.size(); i++){
		if (virus_idx[i]){
			check[virus[i].first][virus[i].second] = 0;
			q.push(make_pair(virus[i].first, virus[i].second));

		}
	}
	bfs();

}

void dfs(int num,int depth){
	if (depth == M){
		copymap(check, initcheck);
		spread();
		return;
	}
	for (int i = num + 1; i < virus.size(); i++){
		virus_idx[i] = 1;
		dfs(i,depth+1);
		virus_idx[i] = 0;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 2){
				virus.push_back(make_pair(i, j));
				initcheck[i][j] = -1;
			}
			else if (map[i][j] == 0) initcheck[i][j] = -1;
			else if (map[i][j] == 1) initcheck[i][j] = 1;
		}
	}
	for (int i = 0; i < virus.size(); i++){
		virus_idx[i] = 1;
		dfs(i, 1);
		virus_idx[i] = 0;
	}


	if (minm == 1987654321)cout << "-1";
	else cout << minm;

	return 0;
}