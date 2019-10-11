//19.10.11
//dfs문제인줄 알고 삽질함 풀 수는 있겠으나 구현이 매우 까다로움 && 비효율적
//답을 찾아보니 bfs...
//빨간공 파란공을 일단 움직이고 겹칠경우에만 원래 있던 자리를 참조해서 재조정
//또한 한번 간 자리는 표시해서 stop

#include <iostream>
#include <queue>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)

int n, m, ans=2e9;
int irx, iry, ibx, iby, hx, hy;
char map[10][10];
int visit[10][10][10][10];

//dir 0 오 1 아 2 왼 3 위
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


struct balls{
	int depth;
	int rx, ry, bx, by;
};

int bfs(){
	
	queue <balls> q;
	q.push({ 0, irx, iry, ibx, iby });
	visit[irx][iry][ibx][iby] = 1;
	while (!q.empty()){
		balls cur = q.front(); int depth = q.front().depth;
		q.pop();
		if (depth > 10)return -1;

		if (cur.rx == hx && cur.ry == hy){
			return depth;
		}

		FOR(i, 4){
			int rx = cur.rx; int ry = cur.ry;
			int bx = cur.bx; int by = cur.by;

			while ( map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O'){
				rx += dx[i]; ry += dy[i];
			}
			while ( map[bx + dx[i]][by + dy[i]] != '#' && map[bx][by] != 'O'){
				bx += dx[i]; by += dy[i];
			}

			if (hx == bx&&hy == by)continue;
			if (rx == bx&&ry == by){
				switch (i){
				case 0:
					cur.ry > cur.by ? by-- : ry--;
					break;
				case 1:
					cur.rx > cur.bx ? bx-- : rx--;
					break;
				case 2:
					cur.ry > cur.by ? ry++ : by++;
					break;
				case 3:
					cur.rx > cur.bx ? rx++ : bx++;
					break;
				}
			}
			if (visit[rx][ry][bx][by])continue;
			
			visit[rx][ry][bx][by] = 1;
			q.push({ depth + 1, rx, ry, bx, by });
		}
		
	}
	return -1;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	FOR(i,n) cin >> map[i];

	FOR(i, n)FOR(j, m){ 
		if (map[i][j] == 'B'){
			ibx = i; iby = j;
		}
		else if (map[i][j] == 'R'){
			irx = i; iry = j;
		}
		else if (map[i][j] == 'O'){
			hx = i; hy = j;
		}
	}

	cout<<bfs();

	return 0;
}