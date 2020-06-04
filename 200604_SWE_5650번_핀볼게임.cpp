
#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef struct holl{
	int x, y;
};

int n, ans, tans;
int map[100][100];
vector <holl> v[11];
// dir 0 ¿À 1 ¾Æ 2 ¿Þ 3 À§
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void start(int x, int y, int dir){
	int sx = x, sy = y;

	while (1){

		x += dx[dir]; y += dy[dir];

		if (x < 0){
			dir = 1; tans++; continue;
		}
		else if (y < 0){
			dir = 0; tans++; continue;
		}
		else if (x >= n){
			dir = 3; tans++; continue;
		}
		else if (y >= n){
			dir = 2; tans++; continue;
		}

		int val = map[x][y];
		if (x == sx&&y == sy || val == -1){
			ans < tans ? ans = tans : ans;
			return;
		}
		if (val == 0) continue;
		else if (val == 1)
		{
			tans++;
			if (dir == 0)dir = 2;
			else if (dir == 1) dir = 0;
			else if (dir == 2) dir = 3;
			else if (dir == 3) dir = 1;
		}
		else if (val == 2)
		{
			tans++;
			if (dir == 0)dir = 2;
			else if (dir == 1) dir = 3;
			else if (dir == 2) dir = 1;
			else if (dir == 3) dir = 0;
		}
		else if (val == 3)
		{
			tans++;
			if (dir == 0)dir = 1;
			else if (dir == 1) dir = 3;
			else if (dir == 2) dir = 0;
			else if (dir == 3) dir = 2;
		}
		else if (val == 4)
		{
			tans++;
			if (dir == 0)dir = 3;
			else if (dir == 1) dir = 2;
			else if (dir == 2) dir = 0;
			else if (dir == 3) dir = 1;
		}
		else if (val == 5)
		{
			tans++;
			if (dir == 0)dir = 2;
			else if (dir == 1) dir = 3;
			else if (dir == 2) dir = 0;
			else if (dir == 3) dir = 1;
		}
		else if (val == 6)
		{
			if (v[6][0].x == x&&v[6][0].y == y){
				x = v[6][1].x, y = v[6][1].y;
			}
			else {
				x = v[6][0].x, y = v[6][0].y;
			}
		}
		else if (val == 7)
		{
			if (v[7][0].x == x&&v[7][0].y == y){
				x = v[7][1].x, y = v[7][1].y;
			}
			else {
				x = v[7][0].x, y = v[7][0].y;
			}
		}
		else if (val == 8)
		{
			if (v[8][0].x == x&&v[8][0].y == y){
				x = v[8][1].x, y = v[8][1].y;
			}
			else {
				x = v[8][0].x, y = v[8][0].y;
			}
		}
		else if (val == 9)
		{
			if (v[9][0].x == x&&v[9][0].y == y){
				x = v[9][1].x, y = v[9][1].y;
			}
			else {
				x = v[9][0].x, y = v[9][0].y;
			}
		}
		else if (val == 10)
		{
			if (v[10][0].x == x&&v[10][0].y == y){
				x = v[10][1].x, y = v[10][1].y;
			}
			else {
				x = v[10][0].x, y = v[10][0].y;
			}
		}
	
	}
}

void solve(){

	FOR(i, n){
		FOR(j, n){
			if (map[i][j] == 0)
			{
				FOR(k, 4)
				{
					tans = 0;
					start(i, j, k);
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
		memcpy(v, v1, sizeof(v));
		ans = 0;
		cin >> n;
		FOR(i, n)FOR(j, n){
			cin >> map[i][j];
			if (map[i][j] > 5 && map[i][j] < 11){
				v[map[i][j]].push_back({ i, j });
			}
		}

		solve();
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}