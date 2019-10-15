//1630 시작
//1711 초기완성 컴파일 x
//1730완성 but 문제이해잘못 ;;;;;
//1742되긴 되나 제한시간 한참초과
//1844 다시 완성	  
//+30분 디버거의 힘을 빌려 테케 맞음
//swe abs cmath 포함
//+10분 49개 맞음
// n==1 d예외처리 but 똑같..
//memset은 구조체에 해주면 안된다..
/*1
4
-2 0 3 1
-1 0 3 2
1 0 2 3
2 0 2 4
*/
//위 반례가 되지 않는데 내가 설계한 방법으로는 잡아낼 방법을 모르겟다
//항상 정해로 풀자 첫번째풀이가 정해
#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include <cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n, ans;

typedef struct oneso{
	double x, y;
	int dir, k;
};

oneso o[1000];
set <int> tidx[1000], idx[1000];
bool check[1000];



void solve(){

	FOR(i, n){
		oneso c = o[i];
		int cdir = c.dir;
		double max = 3000;

		FOR(j, n) {
			//cout << i << " " << j << "\n";
			if (i == j)continue;

			oneso c1 = o[j];
			int c1dir = c1.dir;
			if (cdir == c1dir) continue;

			double can;


			switch (c1dir){
			case 0:
				if (cdir == 1){
					if (c.y > c1.y&&c.x == c1.x){
						can = abs(c1.y - c.y) / 2.0;
						if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
						if (max == can)  idx[i].insert(j);
					}
				}
				else{
					if (cdir == 2){
						if (c.x > c1.x&&c.y > c1.y){
							if (c1.x - c.x == c1.y - c.y){
								can = abs(c1.x - c.x);
								if (max > can) { max = can; idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}

					}
					else {
						if (c.x < c1.x&&c.y > c1.y){
							if (c.x - c1.x == c1.y - c.y){
								can = abs(c1.y - c.y);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}
					}
				}
				break;
			case 1:
				if (cdir == 0){
					if (c.y < c1.y&&c.x == c1.x){
						can = abs(c1.y - c.y) / 2.0;
						if (max > can) { max = can; idx[i].clear(); idx[i].insert(j); }
						if (max == can)  idx[i].insert(j);
					}
				}
				else{
					if (cdir == 2){
						if (c.x > c1.x&&c.y < c1.y){
							if (abs(c1.x - c.x) == abs(c1.y - c.y)){
								can = abs(c1.x - c.x);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}

					}
					else {
						if (c.x < c1.x&&c.y < c1.y){
							if (abs(c1.x - c.x) == abs(c1.y - c.y)){
								can = abs(c1.y - c.y);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}
					}
				}
				break;
			case 2:
				if (cdir == 3){
					if (c.x < c1.x&&c.y == c1.y){
						can = abs(c.x - c1.x) / 2.0;
						if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
						else if (max == can)  idx[i].insert(j);
					}
				}
				else{
					if (cdir == 1){
						if (c.x < c1.x&&c.y > c1.y){
							if (abs(c.x - c1.x) == abs(c1.y - c.y)){
								can = abs(c1.x - c.x);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}

					}
					else {
						if (c.x < c1.x&&c.y < c1.y){
							if (abs(c1.x - c.x) == abs(c1.y - c.y)){
								can = abs(c1.y - c.y);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}
					}
				}
				break;
			case 3:
				if (cdir == 2){
					if (c.x > c1.x&&c.y == c1.y){
						can = abs(c.x - c1.x) / 2.0;
						if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
						else if (max == can)  idx[i].insert(j);
					}
				}
				else{
					if (cdir == 0){
						if (c.x > c1.x&&c.y < c1.y){
							if (abs(c.x - c1.x) == abs(c1.y - c.y)){
								can = abs(c1.x - c.x);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}

					}
					else {
						if (c.x > c1.x&&c.y > c1.y){
							if (abs(c1.x - c.x) == abs(c1.y - c.y)){
								can = abs(c1.y - c.y);
								if (max > can) { max = can;  idx[i].clear(); idx[i].insert(j); }
								else if (max == can)  idx[i].insert(j);
							}
						}
					}
				}
				break;

			}

		}

	}

	FOR(i, n){
		FOR(j, n){
			if (idx[i].empty() || idx[j].empty())continue;
			if (idx[i].end() != idx[i].find(j) && idx[j].end() != idx[j].find(i)){

				if (!check[i]){
					ans += o[i].k;
					check[i] = 1;
				}
				if (!check[j]){
					ans += o[j].k;
					check[j] = 1;
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
		cin >> n;
		ans = 0;
		memset(check, 0, sizeof(check));
		memcpy(idx, tidx, sizeof(idx));
		memset(o, 0, sizeof(0));
		if (n == 1){ cout << "#" << test_case << " 0\n"; continue; }
		FOR(i, n){
			int x, y, dir, k;
			cin >> x >> y >> dir >> k;
			o[i].x = x + 1000;
			o[i].y = y + 1000;
			o[i].dir = dir;
			o[i].k = k;
		}

		solve();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}