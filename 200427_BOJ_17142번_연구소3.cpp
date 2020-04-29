//0005 시작
//0152 해결

// bfs표기 문제,바이러스가 모두 퍼져있을 경우 처리문제 ,bfs 방문한 곳 처리,nn 범위,조합 알고리즘
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct po {
	int x, y;
};

vector <po> virus;
queue <po> q;
int n, m;
int omap[50][50],tmap[50][50];
int visit[10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 1987654321;


void print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tmap[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void spread() {
	

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (tmap[nx][ny] != -1)continue;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || omap[nx][ny]==1)continue;

			tmap[nx][ny] = tmap[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	//print();

}


int map_check() {
	int maxm=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (tmap[i][j] == -1 && omap[i][j] == 0)
				return 1987654321;
			else if (omap[i][j] == 0 && maxm < tmap[i][j])
				maxm = tmap[i][j];
				
		}
	}

	//cout << maxm << "\n";
	return maxm;
}


void choose_virus(int num,int d) {
	if (d == m) {

		memset(tmap, -1, sizeof(tmap));
		for (int i = 0; i < virus.size(); i++)
			if (visit[i]) {
				tmap[virus[i].x][virus[i].y] = 0;
				q.push({ virus[i].x,virus[i].y });
			}
		
		spread();
		ans = min(ans, map_check());
		return;
	}


	for (int i = num; i < virus.size(); i++) {

		if (visit[i]) continue;

		visit[i] = 1;
		choose_virus(i+1,d + 1);
		visit[i] = 0;
	
	}
	
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> omap[i][j];
			if (omap[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	choose_virus(0,0);

	if (ans == 1987654321)
		cout << "-1";
	else
		cout << ans;
	return 0;
}