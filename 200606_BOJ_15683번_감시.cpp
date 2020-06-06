#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct cctv{
	int x, y;
	int type;
};

int N, M,ans=1e9;

vector<cctv> cctvs;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void set_each(int dir, int g[][8], int x, int y)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= N || ny < 0 || ny >= M)return;
	while (g[nx][ny] == 0 || (g[nx][ny] >= 1 && g[nx][ny] <= 5) || g[nx][ny] == 9){
		if (g[nx][ny] == 0)
			g[nx][ny] = 9;
		nx += dx[dir];
		ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)return;
	}
}

int get_remain(int g[][8])
{
	int tans = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (g[i][j] == 0)
				tans++;
		}
	}

	return tans;
}

void print_ground(int g[][8]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << g[i][j] << " ";
				
		}
		cout << "\n";
	}
	cout << "\n";
}



void pick_cctv(int num, int gro[8][8])
{


	if (num == cctvs.size())
	{
		//print_ground(gro);
		int tans = get_remain(gro);
		if (ans > tans)
			ans = tans;
		return;
	}

	int cctv_type = cctvs[num].type;
	int x = cctvs[num].x;
	int y = cctvs[num].y;
	int ogro[8][8] = { 0, };
	//cout << "gro\n";
	//print_ground(gro);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ogro[i][j] = gro[i][j];


	//cout << "ogro\n";
	//print_ground(ogro);
	if (cctv_type == 1){
		for (int i = 0; i < 4; i++){
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					gro[i][j] = ogro[i][j];
			set_each(i, gro, x, y);
			pick_cctv(num + 1, gro);
		}
	}
	else if (cctv_type == 2){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(0, gro, x, y);
		set_each(2, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(1, gro, x, y);
		set_each(3, gro, x, y);
		pick_cctv(num + 1, gro);
	}
	else if (cctv_type == 3){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(0, gro, x, y);
		set_each(1, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(1, gro, x, y);
		set_each(2, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(2, gro, x, y);
		set_each(3, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(3, gro, x, y);
		set_each(0, gro, x, y);
		pick_cctv(num + 1, gro);

	}
	else if (cctv_type == 4){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(0, gro, x, y);
		set_each(1, gro, x, y);
		set_each(2, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(1, gro, x, y);
		set_each(2, gro, x, y);
		set_each(3, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(2, gro, x, y);
		set_each(3, gro, x, y);
		set_each(0, gro, x, y);
		pick_cctv(num + 1, gro);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				gro[i][j] = ogro[i][j];
		set_each(3, gro, x, y);
		set_each(0, gro, x, y);
		set_each(1, gro, x, y);
		pick_cctv(num + 1, gro);
	}
	else if (cctv_type == 5){
		for (int i = 0; i < 4; i++)
			set_each(i, gro, x, y);
		pick_cctv(num + 1, gro);
	}
	

}


int main(){
	int ground[8][8] = { 0 };
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;


	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> ground[i][j];
			if (ground[i][j] >= 1 && ground[i][j] <= 5)
				cctvs.push_back({ i, j, ground[i][j] });
		}
	}

	pick_cctv(0, ground);
	cout << ans;
	return 0;

}