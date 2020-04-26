//1555 Ω√¿€

#include <iostream>
#include <vector>
#include <map>
#define WHITE 0
#define RED 1
#define BULE 2
using namespace std;

int N, K;
int color[12][12];
vector <int> order[12][12];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

typedef struct mal{
	int idx, x, y, d;
}mal;

map <int , mal> mm;


int mall_move(mal &mall)
{
	int ax = mall.x + dx[mall.d];
	int ay = mall.y + dy[mall.d];

	int going = mall.d;
	
	vector <int> &be = order[mall.x][mall.y];

	if (color[ax][ay] == BULE || ax >= N || ax < 0 || ay >= N || ay < 0){
		if (going <= 1)
			going = (going == 1) ? 0 : 1;
		else
			going = (going == 2) ? 3 : 2;
		int rx = mall.x + dx[going];
		int ry = mall.y + dy[going];
		mall.d = going;
		if (color[rx][ry] == BULE || rx >= N || rx < 0 || ry >= N || ry < 0){
			return 1;
		}
		ax = rx;
		ay = ry;
	}
	vector <int> &after = order[ax][ay];

	if (color[ax][ay] == WHITE){
		int flag = 0;
		vector <int>::iterator it;
		int ercnt = 0;
		for (it = be.begin(); it != be.end(); it++){

			if (mall.idx == *it)
				flag = 1;
			if (flag){
				after.push_back(*it);
				mm[(*it)].x = ax;
				mm[(*it)].y = ay;
				ercnt++;
			}
		}
		for (int i = 0; i < ercnt; i++)
			be.pop_back();

	
	}
	else if (color[ax][ay] == RED){
		int flag = 0;
		vector <int>::iterator it;
		int ercnt = 0;
		for (it = be.begin(); it != be.end(); it++){
			if (mall.idx == *it)
				flag = 1;
			if (flag)
				ercnt++;
		}
		for (int i = 0; i < ercnt; i++){
			after.push_back(be.back());
			mm[be.back()].x = ax;
			mm[be.back()].y = ay;
			be.pop_back();
		}
	}
	if (after.size() >= 4)
		return 0;

	return 1;
}


void printmall(){
	cout << "-----------------------\n";
	for (int i = 0; i < K; i++){
		cout << i << " " << mm[i].x << " " << mm[i].y << " "<<mm[i].d<< " \n" ;
	}
	cout << "-----------------------\n";

}

void printcolor(){
	cout << "-----------------------\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << order[i][j].size() << " ";
		}
		cout << "\n";
	}
	cout << "-----------------------\n";

}

int turn_start(){

	for (int i = 0; i < K; i++){
		mal &mall = mm[i];
		
		if (!mall_move(mall))
			return 0;
		//printcolor();
	}

	//printmall();
	
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> N >> K;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < K; i++){
		int x, y, d;
		cin >> x >> y >> d;
		mm[i] = mal{i, x-1, y-1, d - 1};
		order[x - 1][y - 1].push_back(i);
	}

	int k = 1;
	while (k <= 1000){
		if (!turn_start()){
			cout << k << "\n";
			return 0;
		}
		k++;
	}

	cout << -1 << "\n";

	return 0;
}