//211505?
//2205 커파일완성
//2305 erase할때 범위처리 but 특정 Tc에서 유효인덱스오류
//88 89줄 
//2311while (map[in][ty] == 0&&in<h){in++;}에서in 인덱스 확인필!!!!
//tc 3개 맞음
//2323 map_after에서 ty=h-1 대신 w-1로 하고 있었다..

#include<iostream>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n, w, h,ans=9999999;
int imap[15][12], map[15][12], tmap[15][12];
int order[5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
//w,h 조심!!!
void printmap(){
	cout << "\n";
	FOR(i, h){
		FOR(j, w)
		cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}
int mapcheck(){
	int tmp=0;
	FOR(i, h)FOR(j, w){
		if (map[i][j])tmp++;
	}

	return tmp;
}

void map_after(){
	memset(tmap, 0, sizeof(tmap));
	int tx = 0, ty;
	for (int j = 0; j <w; j++){
		ty = h-1;
		for (int i = h - 1; i >= 0; i--){
			if (map[i][j]){

				tmap[ty][tx]=map[i][j];
				
				ty--;
				//if (ty == -1)break;
			}
		}
		tx++;
	}

	memcpy(map, tmap, sizeof(tmap));
}

void erase(int t,int x,int y){
	map[x][y] = 0;
	t--;

	if (t == 0)return;

	FOR(k, 4){
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
		nx -= dx[k]; ny -= dy[k];
		FOR(i, t){
			nx += dx[k]; ny += dy[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)break;
			if (map[nx][ny] == 0)continue;
			erase(map[nx][ny], nx, ny);

		}

	}

}


void go(){
	//order[0] = 2; order[1] = 2; order[2] = 6;
	memcpy(map, imap, sizeof(map));
	//if (order[0] == 2 && order[1] == 2 && order[2] == 6)
	//printmap();
	//cout << "\n" << n << "\n";
	FOR(i, n){
		int in = 0;
		int ty = order[i];

		while (map[in][ty] == 0&&in<h){
			in++;
		}
		//if (order[0] == 2 && order[1] == 2 && order[2] == 6)printmap();
		if (in >= h)continue;
		erase(map[in][ty], in, ty);
		//cout << "\nbefore\n";
		//printmap();
		map_after();
		//cout << "\nafter\n";
		//printmap();

	}
	int tmp = mapcheck();
	//cout << "\n" << tmp << "\n";
	if(ans>tmp)ans=tmp;


}

void dfs(int depth){
	if (depth == n){
		go();
		return;
	}
	FOR(i, w){
		order[depth] = i;
		dfs(depth + 1);
	}

}


void solve(){

	FOR(i, w){ 
		order[0] = i;
		dfs(1); 
	}

}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
		ans = 999999;
		cin >> n >> w >> h;
		FOR(i, h)FOR(j, w)cin >> imap[i][j];
		solve();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}