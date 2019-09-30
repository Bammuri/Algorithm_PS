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
		if (s_a[i + 1])continue;
		switch (sh[i].d){
			int dis;
			case 1:
				dis = sh[i].s;
				while (dis--){
					if (sh[i].x == 1){
						sh[i].d = 2;
						++sh[i].x;
					}
					else if (sh[i].x >1&&sh[i].x<R) {
						if (sh[i].d == 1) {
							--sh[i].x;
						} else {
							++sh[i].x;
						}
					}
					else if (sh[i].x == R) {
						sh[i].d = 1;
						--sh[i].x;
					}
				}
				break;
			case 2:
				dis = sh[i].s;
				while (dis--){
					if (sh[i].x == 1){
						sh[i].d = 2;
						++sh[i].x;
					}
					else if (sh[i].x >1 && sh[i].x<R) {
						if (sh[i].d == 1) {
							--sh[i].x;
						}
						else {
							++sh[i].x;
						}
					}
					else if (sh[i].x == R) {
						sh[i].d = 1;
						--sh[i].x;
					}
				}
				break;
			case 3:
				dis = sh[i].s;
				while (dis--){
					if (sh[i].y == 1){
						sh[i].d = 3;
						++sh[i].y;
					}
					else if (sh[i].y >1 && sh[i].y<C) {
						if (sh[i].d == 4) {
							--sh[i].y;
						}
						else {
							++sh[i].y;
						}
					}
					else if (sh[i].y == C) {
						sh[i].d = 4;
						--sh[i].y;
					}
				}
				break;
			case 4:
				dis = sh[i].s;
				while (dis--){
					if (sh[i].y == 1){
						sh[i].d = 3;
						++sh[i].y;
					}
					else if (sh[i].y >1 && sh[i].y<C) {
						if (sh[i].d == 4) {
							--sh[i].y;
						}
						else {
							++sh[i].y;
						}
					}
					else if (sh[i].y == C) {
						sh[i].d = 4;
						--sh[i].y;
					}
				}
				break;
		}
	}
}

void catch1 (int dis){
	for (int i = 1; i <=R ; i++)
	{
		int shark_num = map[i][dis];
		if (shark_num) {
			s_a[shark_num] = 1;
			ans += sh[shark_num-1].z;
			//cout<<dis <<" "  << shark_num-1<<" "<<sh[shark_num-1].z << "\n";
			break;
		}
	}
}

void as_map(){
	for (int i = 0; i < M; ++i){
		if (s_a[i+1])continue;
		s1 = sh[i];
		if (map[s1.x][s1.y]){
			if (sh[map[s1.x][s1.y]-1].z > s1.z){
				s_a[i+1] = 1;
			}
			else {
				s_a[map[s1.x][s1.y]] = 1;
				map[s1.x][s1.y] = i+1;
			}
		} else 
		map[s1.x][s1.y] = i+1;
	}
}

void solve(){
	// << "?1" << "\n";
	for (int i = 1; i <= C; ++i){
		//cout << "?2" << "\n";
		memset(map, 0, sizeof(map));
		//cout << "?3" << "\n";
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

	for (int i = 0; i < M; ++i){
		cin >> s1.x >> s1.y >> s1.s >> s1.d >> s1.z;
		if (s1.d == 1 || s1.d == 2)s1.s = s1.s % (2 * (R - 1));
		else s1.s = s1.s % (2 * (C - 1));
		sh.push_back(s1);
	}

	solve();
	cout << ans;

}