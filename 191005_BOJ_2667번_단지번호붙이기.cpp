#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)

int map[25][25],v[25][25];
int N, is_num = 1;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };



void printm(){

	FOR(i, N){ 
		FOR(j, N)cout << map[i][j] << " "; 
		cout << "\n";
	}
}

bool OOR(int x, int y){
	return x < 0 || x >= N || y < 0 || y >= N;
}

void group(int x, int y){
	queue <pair<int, int>> Q;
	Q.push(make_pair(x, y));
	v[x][y] = 1;
	map[x][y] = is_num;
	while (!Q.empty()){
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		FOR(i, 4){
			int nx = x + dx[i], ny = y + dy[i];
			if (OOR(nx, ny) || v[nx][ny] || !map[nx][ny])continue;
			v[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
			map[nx][ny] = is_num;
		}
	}
	is_num++;
}

int main(){

	cin >> N;
	
	FOR(i, N)FOR(j, N){
		scanf_s("%1d", &map[i][j]);
	}

	FOR(i, N)FOR(j, N){
		if (map[i][j]==0||v[i][j]) continue;
		group(i, j);
	}
	vector <int> v(is_num-1, 0);
	FOR(i, N)FOR(j, N){
		if (map[i][j] == 0) continue;
		v[map[i][j]-1]++;
	}
	//printm();
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	FOR(i, v.size()){
		cout << v[i] << "\n";
	}



	
}