#include <cstdio>
#include <queue>

using namespace std;
#define MAX 101
#define X first
#define Y second
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, ans;
int board[MAX][MAX], visit[MAX][MAX], dis[MAX][MAX];

queue <pair<int, int> > q;

bool OOB(int a, int b) {
	return a < 0 || a >= n || b<0 || b >= n;
}

void island() {
	bool vis[MAX][MAX];
	for (int i = 0; i<n; i++) fill(vis[i], vis[i] + n, false);
	int island_number = 1;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {

			if (vis[i][j] || !board[i][j]) continue;
			queue<pair<int, int> >Q;
			Q.push(make_pair(i, j));
			vis[i][j] = true;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				board[cur.X][cur.Y] = island_number;
				for (int dir = 0; dir<4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0)continue;
					Q.push(make_pair(nx, ny));
					vis[nx][ny] = true;
				}
			}
			island_number++;
		}
	}
}

int min_bridge(int x, int y) {
	int dist[MAX][MAX];
	for (int i = 0; i<n; i++) fill(dist[i], dist[i] + n, -1);
	queue<pair<int, int> >Q;
	Q.push(make_pair(x, y));
	dist[x][y] = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
			if (board[nx][ny] == board[x][y]) continue;
			if (board[nx][ny] != 0)
				return dist[cur.X][cur.Y];

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
	return 99999;
}


int main() {
	scanf_s("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			scanf_s("%d", &board[i][j]);
	island();
	int ans = 0x7f7f77ff;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (board[i][j] == 0)continue;
			ans = min(ans, min_bridge(i, j));
		}
	}
	printf("%d", ans);
	return 0;
}