#include <iostream>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;


struct lo {
	int x, y;
};

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int R, C, answer=-1;
char map[50][51];
int visit[50][51];

int sx, sy, qx=-1, qy=-1;
queue <lo> wq,bq;



void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}
void bfs() {
	int time = 0;

	while (1) {
		//cout << "s";
		int n = wq.size();
		while(n--) {
			int x = wq.front().x;
			int y = wq.front().y;

			wq.pop();
			FOR(i, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == 'X' || map[nx][ny] == 'D'|| map[nx][ny] == '*') continue;
				
					map[nx][ny] = '*';
					wq.push({ nx,ny });
				

			}
		}
		int a = bq.size();
		while(a--) {

			int x = bq.front().x;
			int y = bq.front().y;
			bq.pop();

			FOR(i, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				//cout << "\n" << nx << " " << ny <<" "<< visit[nx][ny]<<"\n";
				if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == '*' || map[nx][ny] == 'X' || visit[nx][ny]) continue;
				if (map[nx][ny] == 'D') {
					answer = time + 1; break;
				}
				//cout << "\n" << nx << " " << ny << "\n";
				map[nx][ny] = 'S';
				visit[nx][ny] = 1;
				bq.push({ nx,ny });
			}
		}
		time++;
		if (answer != -1)break;
		//cout << "\n" << time << "\n";
		//print();
	}


}


int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S') {
				bq.push({ i,j });
				visit[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				wq.push({ i,j });
			}
		
		}

	}



	bfs();

	if (answer != -1)
		cout << answer;
	else
		cout << "KAKTUS";

	return 0;
}