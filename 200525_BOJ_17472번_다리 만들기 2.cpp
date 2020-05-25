//1234
//1419 TC AC  
//1425 island 배열 크기 6->7 AC 
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


typedef struct br{
	int f, s, len;
};
int N, M;
int map[10][10];
int island_visit[10][10];
int bridge_visit[40];
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
vector <pair<int, int> > island[7];
vector <br> bridge;
int island_idx = 1;
int ans = 1e9;

void get_each(int x, int y, int idx){

	island[idx].push_back(make_pair(x, y));
	island_visit[x][y] = 1;
	queue <pair<int, int> > q;
	q.push(make_pair(x, y));
	map[x][y] = idx;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || !map[nx][ny] || island_visit[nx][ny])continue;
			island_visit[nx][ny] = 1;
			map[nx][ny] = idx;
			island[idx].push_back(make_pair(nx, ny));
			q.push(make_pair(nx, ny));
		}
	}


}

void get_island_xy(){
	memset(island_visit, 0, sizeof(island_visit));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){

			if (!map[i][j] || island_visit[i][j]) continue;

			get_each(i, j, island_idx++);

		}
	}



}
void print_island()
{
	cout << "\n";
	for (int i = 1; i < island_idx; i++){
		for (int j = 0; j <island[i].size(); j++){
			cout<<island[i][j].first << ", " << island[i][j].second << "\n";
		}
		cout << "\n";
	}

}

bool myfind(int first, int second, int len)
{
	for (int i = 0; i < bridge.size(); i++){
		br t = bridge[i];
		if (( t.f == first && t.s == second && t.len == len) || (t.f == second && t.s == first && t.len == len))
			return false;

	}
	return true;
}

void get_each(int x, int y){
	int start_num = map[x][y];

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny]) continue;

		nx += dx[i]; ny += dy[i];

		while (nx >= 0 && nx < N  && ny >= 0 && ny < M)
		{
			if (map[nx][ny])
			{
				int len = abs(nx - x) + abs(ny - y) - 1;
				if (len >1 && myfind(start_num, map[nx][ny],len))
					bridge.push_back({ start_num, map[nx][ny], len });
				break;
			}
			nx += dx[i]; ny += dy[i];
		}
	
	}


}

void make_bridge(){
	for (int i = 1; i < island_idx; i++){
		for (int j = 0; j <island[i].size(); j++){

			get_each(island[i][j].first, island[i][j].second);

		}
	
	}


}

void print_map()
{ 
	cout << "\n";
	for (int i = 0; i < N; i++){

		for (int j = 0; j < M; j++){
			cout<< map[i][j];

		}
		cout << "\n";
	}
}


void print_bridge(){

	for (int i = 0; i < bridge.size(); i++){

		cout << bridge[i].f << "," << bridge[i].s << "," << bridge[i].len << "\n";
	}
}

bool is_connect()
{
	int connect[7][7] = { 0, };
	int landv[7] = { 0, };
	//cout << "\n";
	for (int i = 0; i < bridge.size(); i++)
	{
		if (bridge_visit[i])
		{
			//cout << i << " ";
			connect[bridge[i].f][bridge[i].s] = 1;
			connect[bridge[i].s][bridge[i].f] = 1;
		}
	}

	queue <int> q;
	q.push(1);
	landv[1] = 1;

	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int i = 1; i <island_idx; i++)
		{
			if (connect[num][i] && !landv[i]){
				landv[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 1; i < island_idx; i++){
		if (!landv[i])return false;
	}
	return true;

}

void connect_island(int start,int val){
	if (is_connect())
	{
		if (ans > val)
			ans = val;
	}


	for (int i = start; i < bridge.size(); i++)
	{
		if (bridge_visit[i]) continue;
		bridge_visit[i] = 1;
		connect_island(i + 1,val+bridge[i].len);
		bridge_visit[i] = 0;
	}


}

int sol(){

	get_island_xy();
	//print_island();
	make_bridge();
	//print_map();
	//print_bridge();

	connect_island(0,0);


	if (ans == 1e9)
		return -1;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++){

		for (int j = 0; j < M; j++){
			cin >> map[i][j];

		}
	}


	cout<<sol();


	return 0;
}