#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;


typedef struct sticker {
	int R, C;
	int shape[10][10];
}st;
vector <st> st_vec;

int map[40][40];

void cleanup(st *p){
	for (int i = 0; i < p->C; i++){
		for (int j = 0; j < p->R; j++){
			p->shape[i][j] = 0;
		}
	}
}

void turn90(st *p){
	st sttmp = *p;
	cleanup(p);

	int tmp = p->C;
	p->C = p->R;
	p->R = tmp;

	for (int i = 0; i < p->C; i++){
		for (int j = 0; j < p->R; j++){
			p->shape[i][j] = sttmp.shape[(p->R - 1) - j][i];
		}
	}



}

void stick(st tmp, int x, int y){
	for (int i = 0; i < tmp.C; i++){
		for (int j = 0; j < tmp.R; j++){
			if (tmp.shape[i][j])
				map[x + i][y + j] = tmp.shape[i][j];
		}
	}
}


bool can_stick(st tmp, int x, int y){
	for (int i = 0; i < tmp.C; i++){
		for (int j = 0; j < tmp.R; j++){
			if (tmp.shape[i][j] && map[x + i][y + j])
				return false;
		}
	}
	return true;
}

bool go(st tmp){

	bool stflag = false;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (stflag) return true;
			if (tmp.R + j > M || tmp.C + i > N) continue;
			if (can_stick(tmp, i, j)){
				stick(tmp, i, j);
				stflag = true;
			}

		}
	}
	return stflag;
}

int print(){
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for(int a=0;a<K;a++) {
		st s;

		cin >> s.C >> s.R;
		for (int i = 0; i < s.C; i++){
			for (int j = 0; j < s.R; j++){
				cin>>s.shape[i][j];
			}
		}
		st_vec.push_back(s);
	}


	for (int snum = 0; snum < K; snum++)
	{
		st tmp = st_vec[snum];
		for (int i = 0; i < 4; i++){	

			if (go(tmp))
				break;
			else
				turn90(&tmp);
		}
	
	}

	cout<<print();

	return 0;
}