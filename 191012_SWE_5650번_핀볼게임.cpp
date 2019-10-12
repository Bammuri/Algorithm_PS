/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
//1445분 시작
//1555분 완료
//무한대로 왔다갔다 처리 오류
//홀쌍처리 오류
//vector reset오류
//+= =+오류
//1627 이동똥 -20 1607 예제테케 5개중 4개 성공
//map 초기화 이슈 30분 걸려 해결 but 제출시 시간초과 걸림
//그 후 glo_visit넣고  15분 결려 시간초과 해결 48개 맞음
//2분 인덱스 오타 수정 1715 
//해결 2시간 10분
#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef struct holl{
	int x, y;
};

int n,ans,tans;
int map[100][100], visit[100][100][4], glo_visit[100][100][4];
vector <holl> v[11];
// dir 0 오 1 아 2 왼 3 위
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void start(int x,int y, int dir){
	int sx = x, sy = y;
	//cout << "\n\n" << x << " " << y << " " << dir << "\n";
	while (1){
		//cout << "\n" << x << " " << y << " " << dir << " " << tans<<" "<<ans; "\n";
		x += dx[dir]; y += dy[dir];
		if (visit[x][y][dir])return;
		visit[x][y][dir]++;
		//cout << x << " " << y << " " << dir << " " << tans << " " << ans; "\n";
		if (x < 0){
			dir = 1; tans++; continue;
		} 
		else if (y < 0){ 
			dir = 0; tans++; continue;
		}
		else if (x>=n){
			dir = 3; tans++; continue;
		}
		else if (y>=n){
			dir = 2; tans++; continue;
		}
		//cout << x << " " << y << " " << dir << " " << tans << " " << ans; "\n";
		if (x == sx&&y == sy){
			ans < tans ? ans = tans : ans;
			return;
		}

		switch (map[x][y]){
		case -1:
			ans < tans ? ans = tans : ans;
			return;
		case 0:
			break;
		case 1:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 0;
				break;
			case 2:
				dir = 3;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 2:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
			break;
		case 3:
			tans++;
			switch (dir){
			case 0:
				dir = 1;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 2;
				break;
			}
			break;
		case 4:
			tans++;
			switch (dir){
			case 0:
				dir = 3;
				break;
			case 1:
				dir = 2;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 5:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 6:
			if (v[6][0].x == x&&v[6][0].y == y){
				x = v[6][1].x, y = v[6][1].y;
			}
			else {
				x = v[6][0].x, y = v[6][0].y;
			}
			break;
		case 7:
			if (v[7][0].x == x&&v[7][0].y == y){
				x = v[7][1].x, y = v[7][1].y;
			}
			else {
				x = v[7][0].x, y = v[7][0].y;
			}
			break;
		case 8:
			if (v[8][0].x == x&&v[8][0].y == y){
				x = v[8][1].x, y = v[8][1].y;
			}
			else {
				x = v[8][0].x, y = v[8][0].y;
			}
			break;
		case 9:
			if (v[9][0].x == x&&v[9][0].y == y){
				x = v[9][1].x, y = v[9][1].y;
			}
			else {
				x = v[9][0].x, y = v[9][0].y;
			}
			break;
		case 10:
			if (v[10][0].x == x&&v[10][0].y == y){
				x = v[10][1].x, y = v[10][1].y;
			}
			else {
				x = v[10][0].x, y = v[10][0].y;
			}
			break;
		}
		
	}
}

void solve(){

	FOR(i, n){
		FOR(j, n){
			if (map[i][j] == 0){
				FOR(k, 4){
					if (glo_visit[i][j][k]) continue;
					glo_visit[i][j][k]=1;
					memset(visit, 0, sizeof(visit));
					tans = 0;
					start(i,j,k);
					int ii = i; int jj = j;
					switch (k){
					case 0:
						while (map[ii][jj] == 0&&jj<n){
							glo_visit[ii][jj][k] = 1;
							jj++;
						}
						break;
					case 1:
						while (map[ii][jj] == 0 && ii<n){
							glo_visit[ii][jj][k] = 1;
							ii++;
						}
						break;
					case 2:
						while (map[ii][jj] == 0 && jj>=0){
							glo_visit[ii][jj][k] = 1;
							jj--;
						}
						break;
					case 3:
						while (map[ii][jj] == 0 && ii >= 0){
							glo_visit[ii][jj][k] = 1;
							ii--;
						}
						break;
			
					}

				}
			}
		}
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
		vector <holl> v1[11];
		memcpy( v,  v1,sizeof(v));
		memset(map, 0, sizeof(map));
		memset(glo_visit, 0, sizeof(glo_visit));
		ans= 0;
		cin >> n;
		FOR(i, n)FOR(j, n){
			cin >> map[i][j];
			if (map[i][j] > 5 && map[i][j] < 11){
				v[map[i][j]].push_back({ i, j });
			}
		}

		solve();
		cout << "#" << test_case << " " << ans <<"\n";
	}
	return 0;
}