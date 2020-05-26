//1820
//1922 완성 but TC WA
//2000 TC AC 시간초과,red와 green 각각 판별 green에서 진행된 것도 flower로 cnt 됫엇음
//2005 AC 순열 ->조합
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#define WATER 0
#define SOIL -1
#define FLOWER -2
using namespace std;

int N, M, G, R,ans;
int map[50][50],tmap[50][50];
int visit[10];
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
typedef struct lo{
	int x, y;
};

deque <lo> qr,qrt;
deque <lo> qg,qgt;

vector<lo> spreadingVector;


void print_map(int time){
	cout << "\n" << ans << " " << time << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j]>=0)
				cout << "+";
			cout<<map[i][j]<<" ";
		}
		cout << "\n";
	}


}

void spreadging()
{
	deque <lo> qr(qrt);
	deque <lo> qg(qgt);
	int tmp=0;
	int time = 1;
	//red spread
	while (!qr.empty() || !qg.empty()){
		int s = qr.size();
		while (s--){
			int x = qr.front().x;
			int y = qr.front().y;
			qr.pop_front();

			if (map[x][y] == FLOWER)continue;

			for (int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
				if (map[nx][ny] != SOIL)continue;
				map[nx][ny] = time;
				qr.push_back({ nx, ny });
			}
		}
		//print_map(time);
		time++;
		//green spread
		s = qg.size();
		while (s--){
			int x = qg.front().x;
			int y = qg.front().y;
			qg.pop_front();

			for (int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
				if (map[nx][ny] == WATER || map[nx][ny] == FLOWER)continue;
				
				if (map[nx][ny] == time-1){
					map[nx][ny] = FLOWER;
					tmp++; continue;
				}
				if (map[nx][ny] == SOIL){
					map[nx][ny] = time;
					qg.push_back({ nx, ny });
				}
			}
		}
		//print_map(time);
		time++;

	}
	
	if (ans < tmp)
		ans = tmp;

	//cout << "\n\n\n\nend\n\n\n\n\n";
}





void dfsG(int depth, int start)
{
	if (depth == G)
	{
		memcpy(map, tmap, sizeof(map));
		spreadging();
		return;
	}

	for (int i = start; i < spreadingVector.size(); i++)
	{

		if (visit[i])continue;
		visit[i] = 1;
		lo t = spreadingVector[i];
		qgt.push_back(t);
		tmap[t.x][t.y] = 0;
		dfsG(depth + 1, i + 1);
		tmap[t.x][t.y] = SOIL;
		qgt.pop_back();
		visit[i] = 0;

	}


}


void dfsR(int depth, int start)
{
	if (depth == R){
		dfsG(0, 0);
		return;
	}

	for (int i = start; i < spreadingVector.size(); i++)
	{
		if (visit[i])continue;
		
		visit[i] = 1;
		lo t = spreadingVector[i];
		qrt.push_back(t);
		tmap[t.x][t.y] = 0;
		dfsR(depth + 1, i + 1);
		tmap[t.x][t.y] = SOIL;
		qrt.pop_back();
		visit[i] = 0;

	}


}


int sol(){
	memcpy(tmap, map, sizeof(map));
	dfsR(0,0);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];

			if (map[i][j] == 2){
				spreadingVector.push_back({ i, j });
				map[i][j] = SOIL;
			}
			else if (map[i][j] == 1)
				map[i][j] = SOIL;
			
		}
	}

	cout<<sol();

	return 0;
}