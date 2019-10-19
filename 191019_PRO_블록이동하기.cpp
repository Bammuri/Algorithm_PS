//1900
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> map;

struct robot{
	int x, y, x1, y1;
};
int visit[100][100][100][100];
int dx[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n;


int bfs(){
	queue <robot> q;
	q.push({ 0, 0, 0, 1 });
	visit[0][0][0][1] = 1;
	visit[0][1][0][0] = 1;
	int ans = 0;
	while (!q.empty()){
		int t = q.size();
		//cout<<"\n";
		while (t--){
			int x = q.front().x;
			int y = q.front().y;
			int x1 = q.front().x1;
			int y1 = q.front().y1;
			//cout<<x<<" "<< y<<" "<<x1<<" "<<y1<<"\n";
			if ((x == n - 1 && y == n - 1) || (x1 == n - 1 && y1 == n - 1)){
				return ans;
			}

			q.pop();
			for (int i = 0; i<8; i++){
				if (i<4){
					int nx = x + dx[i]; int ny = y + dy[i]; int nx1 = x1 + dx[i]; int ny1 = y1 + dy[i];
					if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
					if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || visit[nx][ny][nx1][ny1] || visit[nx1][ny1][nx][ny])continue;
					visit[nx][ny][nx1][ny1] = 1;
					visit[nx1][ny1][nx][ny] = 1;
					q.push({ nx, ny, nx1, ny1 });
				}
				else {
					for (int k = 0; k<1; k++){
						int nx = x; int ny = y; int nx1 = x1 + dx[i]; int ny1 = y1;
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || (nx == nx1&&ny == ny1))continue;
						ny1 += dy[i];
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || visit[nx][ny][nx1][ny1] || visit[nx1][ny1][nx][ny])continue;
						if (nx == nx1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
						if (ny == ny1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
					}
					for (int k = 0; k<1; k++){
						int nx = x; int ny = y; int nx1 = x1; int ny1 = y1 + dy[i];
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || (nx == nx1&&ny == ny1))continue;
						nx1 += dx[i];
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || visit[nx][ny][nx1][ny1] || visit[nx1][ny1][nx][ny])continue;
						if (nx == nx1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
						if (ny == ny1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
					}
					for (int k = 0; k<1; k++){
						int nx = x; int ny = y + dy[i]; int nx1 = x1; int ny1 = y1;
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || (nx == nx1&&ny == ny1))continue;
						nx += dx[i];
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || visit[nx][ny][nx1][ny1] || visit[nx1][ny1][nx][ny])continue;
						if (nx == nx1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
						if (ny == ny1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
					}
					for (int k = 0; k<1; k++){
						int nx = x + dx[i]; int ny = y; int nx1 = x1; int ny1 = y1;
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || (nx == nx1&&ny == ny1))continue;
						ny += dy[i];
						if (nx<0 || nx >= n || ny<0 || ny >= n || nx1<0 || nx1 >= n || ny1<0 || ny1 >= n)continue;
						if (map[nx][ny] == 1 || map[nx1][ny1] == 1 || visit[nx][ny][nx1][ny1] || visit[nx1][ny1][nx][ny])continue;
						if (nx == nx1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
						if (ny == ny1){
							visit[nx][ny][nx1][ny1] = 1;
							visit[nx1][ny1][nx][ny] = 1;
							q.push({ nx, ny, nx1, ny1 });
						}
					}
				}

			}
		}

		ans++;
	}
	ans++;
	//if(ans==8)return 0;


}

int solution(vector<vector<int>> board) {
	map = board;
	n = board.size();


	int answer = bfs();
	return answer;
}