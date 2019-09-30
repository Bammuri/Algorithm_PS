// 12ms
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int R, C, M,ans;

int map[101][101];
int s_a[10001];

typedef struct shark{
	int x, y;
	int s, d;
	int z;
}s_st;

s_st s1;
vector <shark> sh;

void move(){
	for (int i = 0; i < M; ++i){
		if (s_a[i])continue;
		switch (sh[i].d) {
			int x, y, dx, dy,nx,ny;
			case 1:
				x = sh[i].x;
				dx = sh[i].s;
				nx = x - dx;
				while (nx < 1 || nx > R){
					if (nx < 1){
						nx = 2 - nx;
						sh[i].d = 2;
					}
					else {
						nx = 2 * R - nx;
						sh[i].d = 1;
					}
				}
				sh[i].x = nx;
				break;
			case 2:
				x = sh[i].x;
				dx = sh[i].s;
				nx = x + dx;
				while (nx < 1 || nx > R){
					if (nx < 1){
						nx = 2 - nx;
						sh[i].d = 2;
					}
					else {
						nx = 2 * R - nx;
						sh[i].d = 1;
					}
				}
				sh[i].x = nx;
				break;
			case 3:
				y = sh[i].y;
				dy = sh[i].s;
				ny = y + dy;
				while (ny < 1 || ny > C){
					if (ny < 1){
						ny = 2 - ny;
						sh[i].d = 3;
					}
					else {
						ny = 2 * C - ny;
						sh[i].d = 4;
					}
				}
				sh[i].y = ny;
				break;
			case 4:
				y = sh[i].y;
				dy = sh[i].s;
				ny = y - dy;
				while (ny < 1 || ny > C){
					if (ny < 1){
						ny = 2 - ny;
						sh[i].d = 3;
					}
					else {
						ny = 2 * C - ny;
						sh[i].d = 4;
					}
				}
				sh[i].y = ny;
				break;
		}
	}
}

void catch1 (int dis){
	for (int i = 1; i <=R ; i++)
	{
		int shark_num = map[i][dis];
		if (shark_num!=-1) {
			s_a[shark_num] = 1;
			ans += sh[shark_num].z;
			//cout<<dis <<" "  << shark_num<<" "<<sh[shark_num].z << "\n";
			break;
		}
	}
}

void as_map(){
	for (int i = 0; i < M; ++i){
		if (s_a[i])continue;
		s1 = sh[i];
		if (map[s1.x][s1.y]!=-1){
			if (sh[map[s1.x][s1.y]].z > s1.z){
				s_a[i] = 1;
			}
			else {
				s_a[map[s1.x][s1.y]] = 1;
				map[s1.x][s1.y] = i;
			}
		} else 
		map[s1.x][s1.y] = i;
	}
}

void solve(){
	// << "?1" << "\n";
	for (int i = 1; i <= C; ++i){
		memset(map, -1, sizeof(map));
		//cout << "?2" << "\n";
		as_map();
		//cout << "?4" << "\n";
		catch1(i);
		move();
		//cout << "?" << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;

	memset(map, -1, sizeof(map));

	for (int i = 0; i < M; ++i){
		cin >> s1.x >> s1.y >> s1.s >> s1.d >> s1.z;
		if (s1.d == 1 || s1.d == 2)s1.s = s1.s % (2 * (R - 1));
		else s1.s = s1.s % (2 * (C - 1));
		sh.push_back(s1);
		map[s1.x][s1.y] = i;
	}

	solve();
	cout << ans;

}