//1345 시작
//1432 tx완성
//1505 AC q 초기화, 우선순위 문제
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, M;
int map[20][20],visit[20][20];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

typedef struct shark{
	int x, y;
	int size = 2;
	int eat = 0;
};

typedef struct lo{
	int x, y;
	bool operator < (const lo &a) const{
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}
};

shark s;


void get_target(int &x, int &y, int &gotime)
{

	memset(visit, 0, sizeof(visit));
	visit[s.x][s.y] = 1;

	queue <pair<int, int> > q;
	vector<lo> v;

	q.push(make_pair(s.x, s.y));
	gotime = 1;
	
	while (!q.empty())
	{
		int t = q.size();

		while (t--){

			int ax = q.front().first;
			int ay = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = ax + dx[i];
				int ny = ay + dy[i];
				//cout << " check" <<ax<<" "<<ay<<" "<< nx << " " << ny << " " << map[nx][ny] << " " << visit[nx][ny] << " " << s.size << "\n";
				if (nx < 0 || nx >= N || ny < 0 || ny >= N 
					|| map[nx][ny] > s.size || visit[nx][ny])continue;
				
				visit[nx][ny] = 1;
				//cout << " check" << nx << " " << ny << " " <<s.size << "\n";
				if (map[nx][ny] != 0 && map[nx][ny] < s.size)
					v.push_back({ nx, ny });
				else 
					q.push(make_pair(nx, ny));
			}
		}
		if (!v.empty()){
			sort(v.begin(), v.end());
			x = v[0].x; y = v[0].y;
			return;
		}

		gotime++;
	
	}



}

void print_map()
{
	cout << s.x << " " << s.y << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout<< map[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int sol(){
	int time = 0;
	int x = -1, y = -1;
	int gotime = 0;
	while (1)
	{
		x = -1, y = -1;
		get_target(x, y, gotime);

		if (x == -1 && y == -1)
			break;

		time+=gotime;

		map[x][y] = 0;
		s.eat++;
		if (s.eat == s.size){
			s.size++;
			s.eat = 0;
		}
		s.x = x;
		s.y = y;
		//print_map();
	}

	return time;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 9){
				s.x = i;
				s.y = j;
			
				map[i][j] = 0;
			}
		}
	}

	cout<<sol();

	return 0;
}