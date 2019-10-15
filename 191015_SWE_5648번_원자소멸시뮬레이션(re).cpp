//1150 시작
//1230 완성 테케다 맞음 but 시간초과 
//정해를 보니 로직의 오류 visit은 존재한다는 것을 뜻함 but 시간초과
//visit과 col도 초기화 해줄필요가 없음 통과?...
//1252
//memset이 문제였음 4000*4000개의 배열을 모두 초기화 해주다보니 문제 발생
//2-6배이상의 실행시간 차이
#include<iostream>
#include<cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
int o[1000][4];// 0 x축 1 y축 2 방향 3 에너지 
int n,ans;
int visit[4002][4002];
int col[4002][4002];


void erase(int tar){
	int nLast = n - 1;
	o[tar][0] = o[nLast][0];
	o[tar][1] = o[nLast][1];
	o[tar][2] = o[nLast][2];
	o[tar][3] = o[nLast][3];
	n--;
}


void sovle(){
	FOR(i, n){
		o[i][0] = o[i][0] * 2;
		o[i][1] = o[i][1] * 2;
		visit[o[i][0]][o[i][1]]++;
	}

	const int nMax = 4002;

	FOR(i, nMax){


		FOR(j, n){
			int &x = o[j][0];
			int &y = o[j][1];
			int dir = o[j][2];

			visit[x][y]--;
			
			switch (dir){
			case 0: y++;
				break;
			case 1: y--;
				break;
			case 2: x--;
				break;
			case 3: x++;
				break;
			}

			if (x>4000||x<0||y>4000||y<0){
				erase(j);
				j--;
			}
			else {
				visit[x][y]++;
				if (visit[x][y] >= 2) col[x][y] = 1;
			}
		}

		FOR(j, n){
			int x = o[j][0];
			int y = o[j][1];
			int k = o[j][3];
			
			if (col[x][y]){
				if (visit[x][y] == 1)col[x][y] = 0;
				visit[x][y]--;
				ans += k;
				erase(j);
				j--;
			}
		
		}
		if (n == 0)break;
	}

}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		ans = 0;
		FOR(i, n){
			int x, y, dir, k;
			cin >> x >> y >> dir >> k;

			o[i][0] = x+1000;
			o[i][1] = y+1000;
			o[i][2] = dir;
			o[i][3] = k;
		}

		sovle();

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}