//1058 AC 정답큐와 탐색큐 분리, i->dir, dis 거리 while안에서 증가
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int ground[15][15], oground[15][15];
int archer[15];
int M, N, D,ans;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void print_archer()
{
	for (int i = 0; i < M; i++)
	{
		cout << archer[i];
	}
	cout << "\n";

}

void print_ground()
{
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << ground[i][j] << " ";
		}
		cout << "\n";
	}
	
}
bool is_end()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (ground[i][j])return false;
		}
	}
	return true;
}

void start_round()
{

	int round = 0;
	int tans = 0;

	while (round < N && !is_end())
	{
		//print_ground();
		//cout << is_end() << " " << round;
		//catch
		vector <pair<int, int>> mon_lo;
		for (int i = 0; i < M; i++)
		{
			queue<pair<int, int>> q;
			queue<pair<int, int>> ansq;
			if (archer[i])
			{
				if (ground[N - 1][i]){
					mon_lo.push_back({ N - 1, i });
					continue;
				}
				int visit[15][15] = { 0, };
				
				q.push({ N - 1, i });
				visit[N-1][i] = 1;
				int end_flag = 0;
				int dis = 1;
				while (!q.empty() && !end_flag && dis < D)
				{
					int size = q.size();
					while (size--){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						//cout << "what i: " << i << "\n";
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = x + dx[dir];
							int ny = y + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny])continue;
							visit[nx][ny] = 1;
							if (ground[nx][ny]){
								end_flag = 1;
								ansq.push({ nx, ny });
							}
							q.push({ nx, ny });
						}
					}
					if (end_flag)
					{
						int cx = ansq.front().first;
						int cy = ansq.front().second;
						ansq.pop();
						while (!ansq.empty())
						{
							int tx = ansq.front().first;
							int ty = ansq.front().second;
							ansq.pop();
							if (cy > ty){
								cx = tx; cy = ty;
							}
						}
						mon_lo.push_back({ cx, cy });
					}
					dis++;
				}

			}
		}
		//cout <<"size : "<< mon_lo.size()<<"\n";
		for (int i = 0; i < mon_lo.size(); i++){
			int x = mon_lo[i].first;
			int y = mon_lo[i].second;
			if (ground[x][y] == 1)tans++;
			ground[x][y] = 0;
		}
		//cout <<"\n "<< round <<" "<<tans<< "\n ";
		//print_ground();
		//map_move
		for (int i = N - 1; i > 0; i--){
			for (int j = 0; j < M; j++){
				ground[i][j] = ground[i - 1][j];
			}
		}
		for (int j = 0; j < M; j++){
			ground[0][j] = 0;
		}
		
		round++;
	}

	if (ans < tans)
		ans = tans;

}

void set_archer(int d, int s)
{
	if (d == 3){
		memcpy(ground, oground, sizeof(ground));
		//print_archer();
		start_round();
		return;
	}
	for (int i = s; i < M; i++){
		if (archer[i])continue;
		archer[i] = 1;
		set_archer(d+1,i);
		archer[i] = 0;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> oground[i][j];
		}
	}
	set_archer(0,0);

	cout << ans;

	return 0;
}