//1615 시작
//1735 xpzp 4개중 3개맞
//1750
//1시간 더걸려 인덱스 -1 수정,  큐브가 돌아가면 인덱스 변환 수정,큐브가 돌아가면 그 면도 돌아가는 것 수정
//테케 다 맞았으나 틀림..
//인덱스 수정하고 큐브의 뒷면을 돌리면 전개도는 똑같이 돌리는 것(전개도 기준으로 돌리는 것 확인!!) 1시간 소요ㅜ
//하나하나 모두 따라해보기 어림짐작 절대금지!
//5시간 소요
#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

int test_case, n;
char order[1000][3];

char tcube[6][3][3] =
{ { { 'r', 'r', 'r' },
{ 'r', 'r', 'r' },
{ 'r', 'r', 'r' }, },
{ { 'w', 'w', 'w' },
{ 'w', 'w', 'w' },
{ 'w', 'w', 'w' }, },
{ { 'o', 'o', 'o' },
{ 'o', 'o', 'o' },
{ 'o', 'o', 'o' } },
{ { 'y', 'y', 'y' },
{ 'y', 'y', 'y' },
{ 'y', 'y', 'y' } },
{ { 'b', 'b', 'b' },
{ 'b', 'b', 'b' },
{ 'b', 'b', 'b' } },
{ { 'g', 'g', 'g' },
{ 'g', 'g', 'g' },
{ 'g', 'g', 'g' } } }
, cube[6][3][3];

/*
int tcube[6][3][3] =
{ { { 1, 2, 3 },
{ 4, 5, 6 },
{ 7, 8, 9 }, },
{ { 10, 11, 12 },
{ 13, 14, 15 },
{ 16, 17, 18 }, },
{ { 19, 20, 21 },
{ 22, 23, 24 },
{ 25, 26, 27 } },
{ { 28, 29, 30 },
{ 31, 32, 33 },
{ 34, 35, 36 } },
{ { 37, 38, 39 },
{ 40, 41, 42 },
{ 43, 44, 45 } },
{ { 46, 47, 48 },
{ 49, 50, 51 },
{ 52, 53, 54 } } }
, cube[6][3][3];
*/

int F[4][3] = { { 1, 2, -1 }, { 3, 0, -1 }, { 4, -1, 0 }, { 5, -1, 2 } };
int U[4][3] = { { 0, 0, -1 }, { 2, 2, -1 }, { 4, -1, 0 }, { 5, -1, 2 } };
int B[4][3] = { { 1, 0, -1 }, { 3, 2, -1 }, { 4, 0, -1 }, { 5, 0, -1 } };
int D[4][3] = { { 0, 2, -1 }, { 2, 0, -1 }, { 4, -1, 2 }, { 5, -1, 0 } };
int R[4][3] = { { 0, -1, 2 }, { 1, -1, 2 }, { 2, -1, 2 }, { 3, -1, 2 } };
int L[4][3] = { { 0, -1, 0 }, { 1, -1, 0 }, { 2, -1, 0 }, { 3, -1, 0 } };


void solve(){

	FOR(i, n){
		char a = order[i][0];
		char b = order[i][1];
		char tmp[3];
		switch (a){
		case 'F':
			if (b == '+'){
				FOR(k, 3) tmp[k] = cube[1][2][k];
				FOR(k, 3) cube[1][2][k] = cube[5][2][k];
				FOR(k, 3) cube[5][2][k] = cube[3][0][2-k];
				FOR(k, 3) cube[3][0][k] = cube[4][2][2-k];
				FOR(k, 3) cube[4][2][k] = tmp[k];

				FOR(k, 2) tmp[k] = cube[0][0][k];
				FOR(k, 2) cube[0][0][k] = cube[0][2 - k][0];
				FOR(k, 2) cube[0][2 - k][0] = cube[0][2][2 - k];
				FOR(k, 2) cube[0][2][2 - k] = cube[0][k][2];
				FOR(k, 2) cube[0][k][2] = tmp[k];

			}
			else {
				FOR(k, 3) tmp[k] = cube[1][2][k];
				FOR(k, 3) cube[1][2][k] = cube[4][2][k];
				FOR(k, 3) cube[4][2][k] = cube[3][0][2-k];
				FOR(k, 3) cube[3][0][k] = cube[5][2][2-k];
				FOR(k, 3) cube[5][2][k] = tmp[k];


				FOR(k, 2) tmp[k] = cube[0][0][k];
				FOR(k, 2) cube[0][0][k] = cube[0][k][2];
				FOR(k, 2) cube[0][k][2] = cube[0][2][2 - k];
				FOR(k, 2) cube[0][2][2 - k] = cube[0][2 - k][0];
				FOR(k, 2) cube[0][2 - k][0] = tmp[k];
			}
			break;
		case 'U':
			if (b == '+'){

				FOR(k, 3) tmp[k] = cube[2][2][k];
				FOR(k, 3) cube[2][2][k] = cube[5][2-k][2];
				FOR(k, 3) cube[5][k][2] = cube[0][0][k];
				FOR(k, 3) cube[0][0][k] = cube[4][2-k][0];
				FOR(k, 3) cube[4][k][0] = tmp[k];

				FOR(k, 2) tmp[k] = cube[1][0][k];
				FOR(k, 2) cube[1][0][k] = cube[1][2 - k][0];
				FOR(k, 2) cube[1][2 - k][0] = cube[1][2][2 - k];
				FOR(k, 2) cube[1][2][2 - k] = cube[1][k][2];
				FOR(k, 2) cube[1][k][2] = tmp[k];

			}
			else {

				FOR(k, 3) tmp[k] = cube[2][2][k];
				FOR(k, 3) cube[2][2][k] = cube[4][k][0];
				FOR(k, 3) cube[4][k][0] = cube[0][0][2-k];
				FOR(k, 3) cube[0][0][k] = cube[5][k][2];
				FOR(k, 3) cube[5][k][2] = tmp[2-k];

				FOR(k, 2) tmp[k] = cube[1][0][k];
				FOR(k, 2) cube[1][0][k] = cube[1][k][2];
				FOR(k, 2) cube[1][k][2] = cube[1][2][2 - k];
				FOR(k, 2) cube[1][2][2 - k] = cube[1][2-k][0];
				FOR(k, 2) cube[1][2 - k][0] = tmp[k];

			}

			break;
		case 'B':
			if (b == '+'){

				FOR(k, 3) tmp[k] = cube[3][2][k];
				FOR(k, 3) cube[3][2][k] = cube[5][0][2-k];
				FOR(k, 3) cube[5][0][k] = cube[1][0][k];
				FOR(k, 3) cube[1][0][k] = cube[4][0][k];
				FOR(k, 3) cube[4][0][k] = tmp[2-k];

				FOR(k, 2) tmp[k] = cube[2][0][k];
				FOR(k, 2) cube[2][0][k] = cube[2][2 - k][0];
				FOR(k, 2) cube[2][2 - k][0] = cube[2][2][2 - k];
				FOR(k, 2) cube[2][2][2 - k] = cube[2][k][2];
				FOR(k, 2) cube[2][k][2] = tmp[k];

			}
			else {

				FOR(k, 3) tmp[k] = cube[3][2][k];
				FOR(k, 3) cube[3][2][k] = cube[4][0][2-k];
				FOR(k, 3)  cube[4][0][k] = cube[1][0][k];
				FOR(k, 3) cube[1][0][k] = cube[5][0][k];
				FOR(k, 3) cube[5][0][k] = tmp[2-k];

				FOR(k, 2) tmp[k] = cube[2][0][k];
				FOR(k, 2) cube[2][0][k] = cube[2][k][2];
				FOR(k, 2) cube[2][k][2] = cube[2][2][2 - k];
				FOR(k, 2) cube[2][2][2 - k] = cube[2][2 - k][0];
				FOR(k, 2) cube[2][2 - k][0] = tmp[k];
			}
			break;
		case 'D':
			if (b == '+'){

				FOR(k, 3) tmp[k] = cube[0][2][k];
				FOR(k, 3) cube[0][2][k] = cube[5][k][0];
				FOR(k, 3) cube[5][k][0] = cube[2][0][2-k];
				FOR(k, 3) cube[2][0][k] = cube[4][k][2];
				FOR(k, 3) cube[4][k][2] = tmp[2-k];

				FOR(k, 2) tmp[k] = cube[3][0][k];
				FOR(k, 2) cube[3][0][k] = cube[3][2 - k][0];
				FOR(k, 2) cube[3][2 - k][0] = cube[3][2][2 - k];
				FOR(k, 2) cube[3][2][2 - k] = cube[3][k][2];
				FOR(k, 2) cube[3][k][2] = tmp[k];
			}
			else {

				FOR(k, 3) tmp[k] = cube[0][2][k];
				FOR(k, 3) cube[0][2][k] = cube[4][2-k][2];
				FOR(k, 3) cube[4][k][2] = cube[2][0][k];
				FOR(k, 3) cube[2][0][k] = cube[5][2-k][0];
				FOR(k, 3) cube[5][k][0] = tmp[k];

				FOR(k, 2) tmp[k] = cube[3][0][k];
				FOR(k, 2) cube[3][0][k] = cube[3][k][2];
				FOR(k, 2) cube[3][k][2] = cube[3][2][2 - k];
				FOR(k, 2) cube[3][2][2 - k] = cube[3][2 - k][0];
				FOR(k, 2) cube[3][2 - k][0] = tmp[k];
			}
			break;
		case 'R':
			if (b == '+'){

				FOR(k, 3) tmp[k] = cube[2][k][2];
				FOR(k, 3) cube[2][k][2] = cube[1][k][2];
				FOR(k, 3) cube[1][k][2] = cube[0][k][2];
				FOR(k, 3) cube[0][k][2] = cube[3][k][2];
				FOR(k, 3) cube[3][k][2] = tmp[k];

				FOR(k, 2) tmp[k] = cube[4][0][k];
				FOR(k, 2) cube[4][0][k] = cube[4][2 - k][0];
				FOR(k, 2) cube[4][2 - k][0] = cube[4][2][2 - k];
				FOR(k, 2) cube[4][2][2 - k] = cube[4][k][2];
				FOR(k, 2) cube[4][k][2] = tmp[k];

			}
			else {

				FOR(k, 3) tmp[k] = cube[2][k][2];
				FOR(k, 3) cube[2][k][2] = cube[3][k][2];
				FOR(k, 3) cube[3][k][2] = cube[0][k][2];
				FOR(k, 3) cube[0][k][2] = cube[1][k][2];
				FOR(k, 3) cube[1][k][2] = tmp[k];

				FOR(k, 2) tmp[k] = cube[4][0][k];
				FOR(k, 2) cube[4][0][k] = cube[4][k][2];
				FOR(k, 2) cube[4][k][2] = cube[4][2][2 - k];
				FOR(k, 2) cube[4][2][2 - k] = cube[4][2 - k][0];
				FOR(k, 2) cube[4][2 - k][0] = tmp[k];
			}
			break;
		case 'L':
			if (b == '+'){
				FOR(k, 3) tmp[k] = cube[2][k][0];
				FOR(k, 3) cube[2][k][0] = cube[3][k][0];
				FOR(k, 3) cube[3][k][0] = cube[0][k][0];
				FOR(k, 3) cube[0][k][0] = cube[1][k][0];
				FOR(k, 3) cube[1][k][0] = tmp[k];

				FOR(k, 2) tmp[k] = cube[5][0][k];
				FOR(k, 2) cube[5][0][k] = cube[5][2 - k][0];
				FOR(k, 2) cube[5][2 - k][0] = cube[5][2][2 - k];
				FOR(k, 2) cube[5][2][2 - k] = cube[5][k][2];
				FOR(k, 2) cube[5][k][2] = tmp[k];
			}
			else {
				FOR(k, 3) tmp[k] = cube[2][k][0];
				FOR(k, 3) cube[2][k][0] = cube[1][k][0];
				FOR(k, 3) cube[1][k][0] = cube[0][k][0];
				FOR(k, 3) cube[0][k][0] = cube[3][k][0];
				FOR(k, 3) cube[3][k][0] = tmp[k];

				FOR(k, 2) tmp[k] = cube[5][0][k];
				FOR(k, 2) cube[5][0][k] = cube[5][k][2];
				FOR(k, 2) cube[5][k][2] = cube[5][2][2 - k];
				FOR(k, 2) cube[5][2][2 - k] = cube[5][2 - k][0];
				FOR(k, 2) cube[5][2 - k][0] = tmp[k];
			}
			break;
		}
	}
	//FOR(k, 6){
		FOR(i, 3){
			FOR(j, 3)cout << cube[1][i][j] ;
			cout << '\n';
		}



}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(order, 0, sizeof(order));
		memcpy(cube,tcube,sizeof(cube));
		cin >> n;
		FOR(i, n){
			cin >> order[i];
		}
		//최적화 필요없음

		solve();

	}
	return 0;
}