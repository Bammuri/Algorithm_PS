//1030
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, G, R,ans;
int ground[50][50], oground[50][50];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


vector <pair<int, int>> candid;
deque<pair<int, int>> gq;
deque<pair<int, int>> rq;


void print_ground()
{
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout<< oground[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int spreading()
{
	int tans = 0;
	deque<pair<int, int>> g(gq);
	deque<pair<int, int>> r(rq);
	int time = 4;
	

	while (!g.empty() || !r.empty())
	{
		int gsize = g.size();
		int rsize = r.size();

		while (gsize--)
		{
			int x = g.front().first;
			int y = g.front().second;
			g.pop_front();
			if (ground[x][y] == 0)continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
				if (ground[nx][ny] == 0)continue;
				if (ground[nx][ny] == 1){
					ground[nx][ny] = time;
					g.push_back({ nx, ny });
				}
			}
		}

		time++;
		while (rsize--)
		{
			int x = r.front().first;
			int y = r.front().second;
			r.pop_front();
	
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
				if (ground[nx][ny] == 0 || ground[nx][ny] == -1)continue;
				
				if (ground[nx][ny] == time - 1){
					//cout << ground[nx][ny]<<" ";
					ground[nx][ny] = 0;
					
					tans++;
					continue;
				}
				if (ground[nx][ny] == 1){
					ground[nx][ny] = time;
					r.push_back({ nx, ny });
				}
			}
		}
		time++;
		
	}
	//cout << "\n\n\n ";
	return tans;
}


void pick_ground(int s, int g, int r)
{
	if (g == G && r == R){
		//print_ground();
		memcpy(ground, oground, sizeof(oground));
		int tans = spreading();
		if (ans < tans){
			ans = tans;
			//cout << ans<<"\n";
			//print_ground();
		}
		return;
	}


	for (int i = s; i < candid.size(); i++){

		int x = candid[i].first;
		int y = candid[i].second;

		if (g < G){
			gq.push_back({ x, y });
			oground[x][y] = 2;
			pick_ground(i+1, g+1, r);
			oground[x][y] = 1;
			gq.pop_back();
		}

		if (r < R){
			rq.push_back({ x, y });
			oground[x][y] = 3;
			pick_ground(i + 1, g, r + 1);
			oground[x][y] = 1;
			rq.pop_back();

		}


	}


}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> oground[i][j];
			if (oground[i][j] == 2){
				candid.push_back({ i, j });
				oground[i][j] = 1;
			}
		}
	}

	pick_ground(0,0,0);
	cout << ans;

	return 0;
}