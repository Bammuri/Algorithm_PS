//1405 시작
//1450 몰라서 답봄 규칙찾기가 핵심, 재귀인줄 알았는데 재귀가 아니었음
//1520 AC vec 초기화, for 문 증가가 아니라 감소문제

#include <iostream>
#include <vector>
using namespace std;

int N;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0, -1, 0, 1 };
int x, y, d, g;
int map[101][101];
vector <int> vec;

void draw(int x,int y){
	int nx;
	int ny;

	map[x][y] = 1;
	for (int i = 0; i < vec.size(); i++){
		x = x + dx[vec[i]];
		y = y + dy[vec[i]];
		map[x][y] = 1;
	}
	
}

int cnt(){
	int c = 0;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				c++;
		}
	}
	return c;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> x >> y >> d >> g;
		vec.clear();
		vec.push_back(d);
		while (g-- > 0){
			for (int k = vec.size() - 1; k >= 0; k--)
				vec.push_back((vec[k] + 1) % 4);
		}

		draw(x,y);
	}

	cout<<cnt();
	return 0;
}