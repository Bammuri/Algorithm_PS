//1511 
//1606 tx완성
//1621 AC 처음 상어 맵에 표시 , 상어 인덱스 표기 오류, 안잡혓을때 예외
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int R, C, M;

typedef struct shark{
	int x, y, speed, dir, size,val;
};

int map[100][100],tmap[100][100];
vector <shark> svec;

int shark_catch(int t){
	int idx;
	for (int i = 0; i < R; i++){
		if (map[i][t]){
			idx = map[i][t] - 1;
			svec[idx].val = 0;
			map[i][t] = 0;
			return svec[idx].size;
		}
	}
	return 0;
}

void shark_move(){
	memset(tmap, 0, sizeof(tmap));
	for (int i = 0; i < M; i++){
		if (svec[i].val){

			if (svec[i].dir == 0){
				svec[i].speed %= 2*R - 2;
				svec[i].x -= svec[i].speed;
				if (svec[i].x < 0){
					svec[i].x *= -1;
					svec[i].dir = 1;
					if (svec[i].x > R-1){
						svec[i].x = (R - 1) - (svec[i].x - (R - 1));
						svec[i].dir = 0;
					}
				}
			}
			else if (svec[i].dir == 1){
				svec[i].speed %= 2*R - 2;
				svec[i].x += svec[i].speed;
				if (svec[i].x > R-1){
					svec[i].x = (R - 1) - (svec[i].x - (R - 1));
					svec[i].dir = 0;
					if (svec[i].x < 0){
						svec[i].x *= -1;
						svec[i].dir = 1;
					}
				}

			}
			else if (svec[i].dir == 2){
				svec[i].speed %= 2*C - 2;
				svec[i].y += svec[i].speed;
				if (svec[i].y > C - 1){
					svec[i].y = (C - 1) - (svec[i].y - (C - 1));
					svec[i].dir = 3;
					if (svec[i].y < 0){
						svec[i].y *= -1;
						svec[i].dir = 2;
					}
				}

			}
			else if (svec[i].dir == 3){
				svec[i].speed %= 2*C - 2;
				svec[i].y -= svec[i].speed;
				if (svec[i].y < 0){
					svec[i].y *= -1;
					svec[i].dir = 2;
					if (svec[i].y > C - 1){
						svec[i].y = (C - 1) - (svec[i].y - (C - 1));
						svec[i].dir = 3;
					}
				}

			}
			if (!tmap[svec[i].x][svec[i].y])
				tmap[svec[i].x][svec[i].y] = i+1;
			else{
				int tidx = tmap[svec[i].x][svec[i].y]-1;

				if (svec[i].size < svec[tidx].size){
					svec[i].val = 0;
				}
				else{
					svec[tidx].val = 0;
					tmap[svec[i].x][svec[i].y] = i+1;
				}

			}

		}

	}

}

void print_map(){

	cout << "\n";
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){

			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	
}

int sol(){
	int gram = 0;
	for (int i = 0; i < C; i++){
		//print_map();
		gram += shark_catch(i);
		//print_map();
		shark_move();
		memcpy(map, tmap, sizeof(map));
	}
	return gram;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		svec.push_back({ x-1, y-1, s, d-1, z,1 });
		map[x - 1][y - 1] = i+1;
	}

	cout<<sol();
	return 0;
}