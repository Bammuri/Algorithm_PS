#include <iostream>
#include <queue>

using namespace std;

int N, M, G, R,MAXf =0;
int map[50][50],tmap[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct point{
	int x, y;
}p;

queue <p> gq,rq;


void minus2(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (tmap[i][j] == 5 || tmap[i][j] == 6)
				tmap[i][j] -= 2;
		}
	}
}

int cnt7(){
	int count = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (tmap[i][j] == 7)
				count++;
		}
	}
	return count;
}

int spread(){
	queue <p> tgq = gq;
	queue <p> trq = rq;

	while (!tgq.empty()&&!trq.empty()){
		int gqsize = tgq.size();
		while (gqsize--){
			p nowp = tgq.front();
			tgq.pop();
			for (int k = 0; k < 4; k++){
				int nx = nowp.x + dx[k];
				int ny = nowp.y + dy[k];

				if (tmap[nx][ny] == 5 && tmap[nowp.x][nowp.y] == 4){
					tmap[nx][ny] = 7; 
				}
				else if (tmap[nx][ny] == 6 && tmap[nowp.x][nowp.y] == 3){
					tmap[nx][ny] = 7; 
				}
				else if (tmap[nx][ny] == 1 || tmap[nx][ny] == 2){
					tmap[nx][ny] = 5;
					tgq.push({ nx, ny });
				}
			}
		}

		int rqsize = trq.size();
		while (rqsize--){
			p nowp = trq.front();
			trq.pop();
			for (int k = 0; k < 4; k++){
				int nx = nowp.x + dx[k];
				int ny = nowp.y + dy[k];

				if (tmap[nx][ny] == 5 && tmap[nowp.x][nowp.y] == 4){
					tmap[nx][ny] = 7; 
				}
				else if (tmap[nx][ny] == 6 && tmap[nowp.x][nowp.y] == 3){
					tmap[nx][ny] = 7; 
				}
				else if (tmap[nx][ny] == 1 || tmap[nx][ny] == 2){
					tmap[nx][ny] = 6;
					trq.push({ nx, ny });
				}
			}
		}
		minus2();
	}
	return cnt7();
}


void dfs(int g, int r)
{
	if (G == g && R == r){

		memcpy(tmap, map, sizeof(map));
		int n = spread();
		if (MAXf < n)
			MAXf = n;
		
		return;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 2){
				if (g < G){
					map[i][j] = 3;
					gq.push({ i, j });
					dfs(g + 1, r);
					map[i][j] = 2;
					gq.pop();
				}
				if (r < R){
					map[i][j] = 4;
					rq.push({ i, j });
					dfs(g, r + 1);
					map[i][j] = 2;
					rq.pop();
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	

	dfs(0, 0);


	cout << MAXf;
	

	
}