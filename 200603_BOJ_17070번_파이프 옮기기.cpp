
//0952AC
#include <iostream>
using namespace std;

int N;
int visit[16][16];
int ans;
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };


//type 0 가로 /1 세로 /2 대각
void dfs(int type, int r, int c)
{
	if (r == N-1&&c == N-1){
		ans++;
		return;
	}
	

	for (int i = 0; i < 3; i++)
	{
		if (type == 0 && i == 1)continue;
		if (type == 1 && i == 0)continue;
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if ((i == 0 && visit[nx][ny]) || (i == 1 && visit[nx][ny]))continue;
		if (i == 2 && (visit[nx][ny] || visit[nx - 1][ny] || visit[nx][ny - 1])) continue;
		visit[nx][ny] = 1;
		if (i == 2){
			visit[nx - 1][ny] = 1;
			visit[nx][ny - 1] = 1;
		}
		dfs(i, nx, ny);
		visit[nx][ny] = 0;
		if (i == 2){
			visit[nx - 1][ny] = 0;
			visit[nx][ny - 1] = 0;
		}
	}



}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> visit[i][j];
		}
	}

	visit[0][0] = 1;
	visit[0][1] = 1;
	dfs(0, 0, 1);

	cout << ans;
	return 0;
}