//´ë·« 60ºÐ
#include <iostream>
#include <queue>
using namespace std;

int around_info[50][50], map[50][50];
int n, m;
int visit[50][50];


int room_size[50];
int dx[] = { 0, 0, -1, 0, 0, 0, 0, 0, 1 };
int dy[] = { 0, -1, 0, 0, 1, 0, 0, 0, 0 };


void print_map()
{
	cout << "\n";
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout<<map[i][j];
		}
		cout << "\n";
	}
}


void mark_room(int x, int y, int room_cnt)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	map[x][y] = room_cnt;
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 1; i <= 8; i *= 2){
			if (i & around_info[x][y]) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
			if (map[nx][ny] == 0){
				map[nx][ny] = room_cnt;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
	room_size[room_cnt] = cnt;
}

int get_big_room(int room_cnt)
{
	int big = 0;
	for (int i = 0; i <= room_cnt; i++){
		if (big < room_size[i])
			big = room_size[i];
	}

	return big;
}

int get_room_connection(int x, int y)
{
	queue<pair<int, int>> q;
	int room_num = map[x][y];
	int big = room_size[room_num];
	visit[x][y] = 1;
	q.push({ x, y });
	

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 1; i <= 8; i *= 2){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
			if (map[nx][ny] == room_num){
				if (visit[nx][ny])continue;
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
			else{
				int order_room = map[nx][ny];
				if (big < room_size[room_num] + room_size[order_room])
					big = room_size[room_num] + room_size[order_room];
			}
		}

	}

	return big;
}

int get_onecut_big_room(int room_cnt){
	int ans = 0;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (visit[i][j])continue;
			int tans = get_room_connection(i, j);
			if (ans < tans)
				ans = tans;
		}
	}

	return ans;
}

void sol(){
	int room_cnt = 1;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (map[i][j] != 0)continue;

			mark_room(i, j, room_cnt++);
		}
	}
	//print_map();
	cout << room_cnt - 1 << "\n";
	cout << get_big_room(room_cnt - 1) << "\n";
	cout << get_onecut_big_room(room_cnt - 1) << "\n";

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> around_info[i][j];
		}
	}

	sol();


	return 0;
}