//1427 시작
//m,n 조심
//1508 tc 1개중 1개 맞음
//expected unqualified-id before ‘or’ token백준 컴파일 에러
//or가 예약어라 그런듯 제출 but 런타임 error
//1536 27줄 tmp 인덱스 오류 성공
#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

int n, m, k,ans=999999;
int imap[51][51],map[51][51];
int turna[7][3];
int order[7];
int visit[7];

void printmap(){
	cout << "\n";
	FOR(i, n){ FOR(j, m)cout << map[i][j] << " "; 	cout << "\n"; }
	cout << "\n";
}

void turning(int x,int y,int d){
	x--; y--;

	int tmp[1000];
	for (int i = d; i > 0;i--){
		int k = i * 2;
		FOR(j, k) tmp[j] = map[x - i][y + i - 1 - j];
		FOR(j, k) map[x - i + j][y - i] = map[x - i + 1 + j][y - i];
		FOR(j, k) map[x + i][y - i + j] = map[x + i][y - i + 1 + j];
		FOR(j, k) map[x + i-j][y + i] = map[x + i-1-j][y + i];
		FOR(j, k) map[x - i][y + i-j] = tmp[j];
	}

}

void go(){

	FOR(i, k){
		int or1=order[i];
		//돌리고
		turning(turna[or1][0], turna[or1][1], turna[or1][2]);
		//printmap();
	}

	//계산해서 최소값 갱신
	int tmin = 9999999;
	FOR(i, n){
		int tmp=0;
		FOR(j, m) tmp += map[i][j];

		if (tmin > tmp)tmin = tmp;
	}
	if (ans > tmin)ans = tmin;
	
	

}

void dfs(int depth){
	if (depth == k){
		//cout << "\n";
		//FOR(i,k)cout<<order[i]<<" ";
		//cout << "\n";
		memcpy(map, imap, sizeof(map));
		go();
		return;
	}

	FOR(i, k){

		if (visit[i])continue;
		visit[i] = 1;
		order[depth] = i;
		dfs(depth + 1);
		visit[i] = 0;

	}


}

void solve(){
	
	FOR(i, k){
		
		visit[i]=1;
		order[0] = i;
		dfs(1);
		visit[i] = 0;
	}

	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ans = 9999999;
	cin >> n >> m >> k;

	FOR(i, n)FOR(j, m) cin >> imap[i][j];

	FOR(i, k)FOR(j, 3) cin >> turna[i][j];

	solve();

	return 0;
}