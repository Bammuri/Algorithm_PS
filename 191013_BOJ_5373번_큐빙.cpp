//1615 ����
//1735 xpzp 4���� 3����
//1750
//1�ð� ���ɷ� �ε��� -1 ����,  ť�갡 ���ư��� �ε��� ��ȯ ����,ť�갡 ���ư��� �� �鵵 ���ư��� �� ����
//���� �� �¾����� Ʋ��..
//�ε��� �����ϰ� ť���� �޸��� ������ �������� �Ȱ��� ������ ��(������ �������� ������ �� Ȯ��!!) 1�ð� �ҿ��
//�ϳ��ϳ� ��� �����غ��� ����� �������!
//5�ð� �ҿ�
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
		//����ȭ �ʿ����

		solve();

	}
	return 0;
}