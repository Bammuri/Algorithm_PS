#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct lo{
	int x, y, dir;
	long long cost;
	bool operator < (const lo &o) const{
		if (cost == o.cost)
			return x + y<o.x + o.y;
		return cost>o.cost;
	}
}lo;

priority_queue<lo> pq;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int s;


void print_visit(long long visit[][26]){
	cout << "\n";
	for (int i = 0; i < s; i++){
		for (int j = 0; j < s; j++){
			cout << visit[i][j] << " ";
		}
		cout << "\n";

	}
	cout << "\n";
}

long long bfs(vector<vector<int>> &board){
	long long visit[26][26][4] = { 0, };
	pq.push({ 0, 0, -1, 0 });

	while (!pq.empty())
	{
		lo now = pq.top();
		pq.pop();

		for (int i = 0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx <0 || nx >= s || ny <0 || ny >= s || board[nx][ny])continue;
			if (now.dir == -1 || now.dir == i){
				if (visit[nx][ny][i] == 0 || visit[nx][ny][i] >= now.cost + 100){
					visit[nx][ny][i] = now.cost + 100;
					pq.push({ nx, ny, i, now.cost + 100 });
				}
			}
			else{
				if (visit[nx][ny][i] == 0 || visit[nx][ny][i] >= now.cost + 600){
					visit[nx][ny][i] = now.cost + 600;
					pq.push({ nx, ny, i, now.cost + 600 });
				}
			}
		}
	}
	int mx = 1e9;
	for (int i = 0; i < 4; i++){
		if (visit[s - 1][s - 1][i] != 0 && mx > visit[s - 1][s - 1][i])
			mx = visit[s - 1][s - 1][i];
	}

	return mx;
}

long long solution(vector<vector<int>> board) {
	long long answer = 0;
	s = board.size();

	answer = bfs(board);
	return answer;
}

int main(){
	vector<vector<int>> board = 
	{ { 0, 0, 0 }, 
	{ 0, 0, 0 }, 
	{ 0, 0, 0 } };

	cout << solution(board) << "\n";

	board = 
	{ 
	{ 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 0, 0 },
	{ 1, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } 
	};

	cout << solution(board) << "\n";


	board = { 
	{ 0, 0, 0, 0, 1 },
	{ 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 1, 0, 0, 0, 0 } };

	cout << solution(board) << "\n";

	board = { { 0, 0, 1, 0 }, { 0, 0, 0, 0 }, { 0, 1, 0, 1 }, { 1, 0, 0, 0 } };
	cout << solution(board) << "\n";
	//2100

	board = { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1 }, {0, 0, 0, 0, 0, 0}};
	cout << solution(board) << "\n";
	//3200

	board =
	{
		{ 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 1 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0 }

	};
	// 3700
	cout << solution(board) << "\n";

	return 0;
}