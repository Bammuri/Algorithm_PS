//1150 시작
//1206 완성 케테 6개중 5개 맞음 operator<오류
//1319 테케 다맞 제출 45프로 오류
//1424 조합 m <-n 때문에... 2시간 30분;;
#include <iostream>
#include <queue>
#include <algorithm>
#include <algorithm>
#include <cstring>
using namespace std;
 
#define FOR(i,n) for(int i=0;i<n;i++)
int n, m, d,answer;
int imap[16][15], map[16][15], check[16][15], tmap[16][15];
int nums[3];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct eme{
	int x, y;
	bool operator<(const eme& o)const{
		return y < o.y;
	}
};

void bfs(int i){

	queue <eme> q;
	vector <eme> ans;

	q.push({ n, nums[i] });
	int turn = d;
	while (turn--){
		int s = q.size();

		while (s--){
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			FOR(i, 4){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;


				if (map[nx][ny]){//적이 있다면 죽일 수 있는 후보
					ans.push_back({ nx, ny });
				}
				q.push({ nx, ny });
			}
		}
		if (!ans.empty()){
			sort(ans.begin(), ans.end());//거리가 같은 후보들에서 y좌표가 작은 순으로 정렬
			check[ans[0].x][ans[0].y]=1;//각 궁수의 위치에서 죽일 적의 좌표를 check배열에 표시
			return;
		}
	}
}

void go(){
	cout << "num " << nums[0] << nums[1] << nums[2] << "\n";
	int cnt = n;//최대 적이 이동하는 횟수 열의 수 
	int tmp = 0;
	while (cnt--){
		FOR(i, 3){
			bfs(i);//각 궁수의 위치에서 죽일 적의 좌표를 check배열에 표시
		}
		
		FOR(a, n)FOR(b, m){

			if (check[a][b]){//죽일 적의 좌표를 check가 되어 있다면 죽이고 증가
				check[a][b] = 0;
				map[a][b] = 0;
				tmp++;
			}
		}
		FOR(a,m)tmap[0][a] = 0;
		FOR(a, n-1)FOR(b, m){
			tmap[a + 1][b] = map[a][b];
		}
		memcpy(map, tmap, sizeof(tmap));

		cout << "\n"<<cnt;
		FOR(i, n){
			FOR(j, m){
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "tmp " << tmp << "\n";
	}

	cout << "tmp " << tmp << "\n";
	if (answer < tmp)answer = tmp;//각 조합에서 최대값 추출

}


void dfs(int ch, int depth){

	if (depth == 3){
		// 3명의 궁수 위치를 뽑으면 화살 시뮬레이션
		memcpy(map, imap, sizeof(imap));
		go();
		return;
	}

		for (int ne = ch + 1; ne < m; ne++){
			nums[depth] = ne;
			dfs(ne, depth + 1);
		}

}


void solve(){

	//nums에 조합으로 궁수를 3명을 넣음 dfs이용
	FOR(i, n){
		nums[0] = i;
		dfs(i, 1);

	}

	cout << answer << "\n";
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//초기화
	cin >> n >> m >> d;

	FOR(i, n)FOR(j, m){
		cin >> imap[i][j];
	}

	solve();

	
	return 0;
}