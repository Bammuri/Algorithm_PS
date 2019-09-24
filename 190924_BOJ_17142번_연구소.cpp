#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, count_2 = 0;
int map[50][50], inicheck[50][50], check[50][50];
vector <pair<int, int>> virus;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void copymap(int(*a)[50], int(*b)[50]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = b[i][j];

}

int count() {
	int maxnum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j])continue;
			if (check[i][j] > maxnum)maxnum = check[i][j];
		}
	return maxnum;
}

bool check_0() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j])continue;
			if (check[i][j] == -1)return true;
		}
	return false;
}

void printcheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << check[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}


void bfs(queue <pair<int, int>> q, int dis) {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (check[nx][ny] != -1)continue;
			check[nx][ny] = check[x][y] + 1;
			q.push(make_pair(nx, ny));

		}

	}

}

int main() {
	int ans = 1987654321;
	count_2 = 0;

	//fill(&map[0][0], &map[0][0]+sizeof(map), 0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				count_2++;
				inicheck[i][j] = 1;
			}
			else if (map[i][j] == 1) {
				inicheck[i][j] = 1;
			}
			else if (map[i][j] == 0) {
				inicheck[i][j] = -1;
			}
		}
	}
	vector <int> permu(M, 1);

	for (int i = 0; i < count_2 - M; i++)
		permu.push_back(0);
	// 무조건 정렬되어 있는 상태여야 한다.
	sort(permu.begin(), permu.end());
	//cout << M << " " << count_2 - M<< " "<<virus.size()<<permu.size();
	do {
		copymap(check, inicheck);
		queue <pair<int, int>> q;
		for (int i = 0; i < permu.size(); i++) {
			if (permu[i]) {
				q.push(make_pair(virus[i].first, virus[i].second));
				check[virus[i].first][virus[i].second] = 0;
			}
			else {
				check[virus[i].first][virus[i].second] = -1;
			}
		}
		bfs(q, 0);
		//printcheck();
		if (check_0()) continue;

		ans = min(ans, count());

	} while (next_permutation(permu.begin(), permu.end()));

	if (ans == 1987654321)cout << "-1";
	else cout << ans;
	return 0;
}