#include <cstdio>
#include <queue>
using namespace std;

int Testcase;
int n, m;
char map[1000][1000];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


bool INR(int x, int y) {
	return x >= 0 && x < m&&y >= 0 && y < n;
}
void printmap() {
	printf("\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}


void solve() {
	queue<pair<int, int> >person;
	queue<pair<int, int> >fire;
	//입력
	for (int a = 0; a < m; a++)
		for (int b = 0; b < n; b++) {
			scanf_s(" %c", &map[a][b]);
			if (map[a][b] == '@')
				person.push(make_pair(a, b));
			else if (map[a][b] == '*')
				fire.push(make_pair(a, b));
		}

	int time = 1;
	while (!person.empty()) {
		//불을 bfs
		for (int i = 0, size = fire.size(); i < size; i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int a = 0; a < 4; a++) {
				int nx = x + dx[a];
				int ny = y + dy[a];

				if (!INR(nx, ny) || map[nx][ny] == '#') continue;
				else if (map[nx][ny] == '@' || map[nx][ny] == '.') {
					map[nx][ny] = '*';
					fire.push(make_pair(nx, ny));
				}
			}
		}
		//사람을 먼저 bfs
		for (int i = 0, size = person.size(); i < size; i++) {
			int x = person.front().first;
			int y = person.front().second;
			person.pop();

			for (int a = 0; a < 4; a++) {
				int nx = x + dx[a];
				int ny = y + dy[a];

				if (!INR(nx, ny)) {
					printf("%d\n", time); return;
				}
				else if (map[nx][ny] == '@' || map[nx][ny] == '#')
					continue;
				else if (map[nx][ny] == '.') {
					map[nx][ny] = '@';
					person.push(make_pair(nx, ny));
				}

			}
		}

		time++;
		printmap();
	}
	printf("IMPOSSIBLE\n");

}

int main() {
	scanf_s("%d", &Testcase);
	for (int i = 0; i < Testcase; i++) {
		scanf_s("%d%d", &n, &m);
		solve();
	}


	return 0;
}