#include <iostream>
#define INF 1e9
using namespace std;

int map[10][10];
int checkcnt[6];
int ans = INF;


void get_next_xy( int &x, int &y)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (map[i][j]) { x = i; y = j; return; }
		}
	}
}

bool is_not_possible(int x, int y, int size)
{
	if (x + size > 10 || y + size > 10 || checkcnt[size] >= 5) return true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (!map[i][j]) return true;
		}
	}

	return false;
}

void change(int r, int c, int size, int val)
{
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			map[i][j] = val;
		}
	}
}

void dfs(int d) {
	if (d > ans) return;

	int x = 10, y = 10;
	get_next_xy(x, y);

	if (x == 10 && y == 10)
	{
		ans = ans > d ? d : ans;
		return;
	}

	for (int i = 5; i >= 1; i--) {
		if (is_not_possible(x, y, i)) continue;
		//cout <<d<<" "<< x << " " << y <<" "<<i<< "\n";
		change(x, y, i, 0);
		checkcnt[i]++;
		dfs(d + 1);
		checkcnt[i]--;
		change(x, y, i, 1);
	}
}

int main(void) {
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	dfs(0);

	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}
