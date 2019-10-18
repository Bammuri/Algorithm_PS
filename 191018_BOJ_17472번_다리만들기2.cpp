//1500분 시작
//1536 화장실
//1550다시 시작
//1635 1차완성
//1718 모든 땅이 연결되어 있는지 판별하는 부분을 몰라 해멤 -> bfs로 가능
//1900 완성했지만 9퍼에서 틀림 모든 tc다해봄... 
//1934 반례 tc 찾음 //visit_land[6->7] 인덱스 오류...
/*10 10
0 0 0 1 1 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
1 0 0 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
0 0 1 1 1 1 0 0 1 1
answer =11
but 12*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n, m,tans,ans=999999;
int map[10][10], visit[10][10], briges[50], connect[7][7], visit_land[7];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int is_n = 1;


struct land{
	int x, y;
};
struct mindisland{
	int l1, l2, dis;
};

vector <land> lands[7];
vector <mindisland> vm;

bool check(int x,int y){
	FOR(i, 4){
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
		if (map[nx][ny] == 0)return true;
	}
	return false;

}

void bfs(int x,int y,int num){

	queue <land> q;
	q.push({ x, y });

	while (!q.empty()){
		int x1 = q.front().x;
		int y1 = q.front().y;

		visit[x1][y1] = 1;
		map[x1][y1] = num;
		lands[num].push_back({ x1, y1 });

		q.pop();

		FOR(i, 4){
			int nx = x1 + dx[i]; int ny = y1 + dy[i];

			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
			if (map[nx][ny] == 0||visit[nx][ny]==1)continue;

			visit[nx][ny] = 1;
			map[nx][ny] = num;
			if (check(nx,ny)) lands[num].push_back({ nx, ny});

			q.push({ nx, ny });
		}

	}

}


void mark_island(){

	FOR(i, n)FOR(j, m){

		if (map[i][j] == 0||visit[i][j])continue;

		bfs(i,j,is_n);
		is_n++;
	}
}

void printm(){
	cout << "\n";
	FOR(i, n){ FOR(j, m)cout << map[i][j] << " "; cout << "\n"; }
	cout << "\n";
}


void get_mindis(int fir,int sec){
	int min = 9999999, tx=-1, ty=-1;
	FOR(i, lands[fir].size()){
		int x = lands[fir][i].x;int y = lands[fir][i].y;
		FOR(j, 4){
			int size = 0;
			int nx = x + dx[j], ny = y + dy[j];
			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;

			while (map[nx][ny]==0){
				if (nx >= n || nx < 0 || ny >= m || ny < 0)break;
				size++;
				nx += dx[j]; ny += dy[j];
			}
			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
			if (map[nx][ny] == sec){

				if (min > size && size > 1){
					tx = fir, ty = sec, min = size;
				}
			}
		}
	}

	if (tx != -1)vm.push_back({ tx, ty, min });
	

}

bool checkall(){
	memset(connect, 0, sizeof(connect));
	memset(visit_land, 0, sizeof(visit_land));
	for (int i = 0; i < vm.size(); i++){
		if (briges[i]){
			int b1 = vm[i].l1, b2 = vm[i].l2;
			connect[b1][b2] = 1;
			connect[b2][b1] = 1;
		}
	}


	queue <int> q;
	q.push(1);
	visit_land[1] = 1;
	while (!q.empty()){
		int cur = q.front();
		q.pop();

		for (int i = 1; i < is_n; ++i){
			if (i == cur)continue;
			if (visit_land[i] == 1 || connect[cur][i] == 0)continue;

			visit_land[i] = 1;
			q.push(i);
		}
	}


	for (int i = 1; i < is_n;++i){
		if (visit_land[i] == 0)return false;
	}
	return true;

}
	

void dfs(int a,int depth) {
	cout << "\n";
	FOR(i, vm.size())cout << briges[i] << " ";
	cout << "\n";
	if (checkall()){
		if (ans>tans)ans = tans;
	}
	if (depth == vm.size()){
		return;
	}
	

	for (int i = a + 1; i < vm.size(); i++){
		briges[i] = 1;
		tans += vm[i].dis;
		dfs(i, depth+1);
		briges[i] = 0;
		tans -= vm[i].dis;
	}

}
void solve(){
	mark_island();
	printm();
	for (int i = 1; i < is_n; i++){
		for (int j = i + 1; j < is_n; j++){
			get_mindis(i, j);
		}
	}

	
	int k = vm.size();
	cout << "\n";
	FOR(i, k){
		cout << vm[i].l1 << " " << vm[i].l2 << " " << vm[i].dis << "\n";
	}
	cout << "\n";
	ans = 999999;
	for (int i = 0; i < k;i++){
		briges[i] = 1;
		tans += vm[i].dis;
		dfs(i,1);
		briges[i] = 0;
		tans -= vm[i].dis;

	}

	if (ans == 999999)ans = -1;
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;//n,m 조심!!!!!!!!!!!!!!!!!!!!!!!!!1

	FOR(i, n)FOR(j, m){
		cin >> map[i][j];
	}

	solve();

	return 0;
}