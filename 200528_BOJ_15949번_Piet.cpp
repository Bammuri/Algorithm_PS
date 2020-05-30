//1155
//1317 TCAC->AC, bfs로 블럭을 판별못함
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char ground[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
typedef struct lo{

	int x, y;
};
vector <char> ans;
int DP = 1, CC = -1;//오른족 ,왼쪽


bool setcmp(const lo &f, const lo &s){
	if (DP == 0)
	{
		if (f.x == s.x){
			if (CC == 1)
				return f.y > s.y;
			else
				return f.y < s.y;
		}
		return f.x < s.x;

	}
	else if (DP == 1)
	{
		if (f.y == s.y){
			if (CC == 1)
				return f.x > s.x;
			else
				return f.x < s.x;
		}
		return f.y > s.y;
	}
	else if (DP == 2)
	{
		if (f.x == s.x){
			if (CC == 1)
				return f.y < s.y;
			else
				return f.y > s.y;
		}
		return f.x > s.x;
	}
	else if (DP == 3)
	{
		if (f.y == s.y){
			if (CC == 1)
				return f.x < s.x;
			else
				return f.x > s.x;
		}
		return f.y < s.y;
	}

}

void setCCDP(int stage)
{
	if (stage == 0)
		return;
	if (stage % 2 == 0)
		DP = (DP + 1) % 4;
	else
		CC *= -1;

}

void getCurBlockLocation(vector <lo> &m, int r, int c)
{
	queue <lo> q;
	int visit[100][100] = { 0, };
	visit[r][c] = 1;
	q.push({ r, c });
	m.push_back({ r, c });
	char curBlock = ground[r][c];

	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (visit[nx][ny] || ground[nx][ny] != curBlock)continue;
			visit[nx][ny] = 1;
			m.push_back({ nx, ny });
			q.push({ nx, ny });

		}


	}

}


char getNextBlock(char curBlock,lo& curLo)
{
	vector <lo> m;
	getCurBlockLocation(m, curLo.x, curLo.y);

	int stage = 0;
	while (stage < 8){
		
		setCCDP(stage);
		
		sort(m.begin(), m.end(), setcmp);
		curLo = m[0];
		lo nextLo = { curLo.x + dx[DP], curLo.y + dy[DP] };
		//cout << DP << " " << CC << " " << nextLo.x << " " << nextLo.y<< "\n";
		//cout << stage << "\n";

		if (nextLo.x >= N || nextLo.x < 0 || nextLo.y >= M || nextLo.y < 0){
			stage++; continue;
		}
		char nextBlock = ground[nextLo.x][nextLo.y];
		if (nextBlock == 'X'){
			stage++; continue;
		}
		curLo = nextLo;
		return nextBlock;

	}
	return '.';
}


void getAns()
{
	lo curLo = { 0, 0 };
	char curBlock = ground[0][0];
	ans.push_back(curBlock);


	while (true){

		curBlock = getNextBlock(curBlock, curLo);
		if (curBlock == '.')
			return;
		ans.push_back(curBlock);
		//for (auto ch : ans)
			//cout << ch;
		//cout << "\n";
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j  < M; j++){
			cin >> ground[i][j];
			//char t = ground[i][j];
			//if (t != 'X')
				//m[t].push_back({ i, j });

		}

	}

	getAns();

	for (auto ch : ans)
		cout << ch;


	return 0;

}