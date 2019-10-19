//1800
//1853 제출 81점
//1856 3번돌려야하는데 2번돌림 100점
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
int map[60][60], m, n;
vector<vector<int>> rkey, rlock;

void go(int k, int p){
	memset(map, 0, sizeof(map));

	for (int i = 0; i<m; i++){
		for (int j = 0; j<m; j++){
			map[21 - m + i + k][21 - m + j + p] = rkey[i][j];
		}
	}

	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			map[20 + i][20 + j] += rlock[i][j];
			if (map[20 + i][20 + j]>1) return;
		}
	}

}

bool check(){
	for (int i = 20; i<20 + n; i++){
		for (int j = 20; j<20 + n; j++){
			if (map[i][j] != 1)return false;
		}
	}
	return true;
}

void turn90(){
	vector<vector<int>> tlock = rlock;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			rlock[i][j] = tlock[j][n - 1 - i];

		}
	}

}
void printmap(){
	cout << "\n";
	for (int i = 20; i<20 + n; i++){

		for (int j = 20; j<20 + n; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void printlock(){
	cout << "lock\n";
	for (int i = 0; i<n; i++){

		for (int j = 0; j<n; j++){
			cout << rlock[i][j] << " ";
		}
		cout << "\n";
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	rkey = key; rlock = lock;

	m = key.size();
	n = lock.size();


	bool answer = 0;
	for (int t = 0; t<4; t++){
		//printlock();
		for (int k = 0; k<m + n - 1; k++){
			for (int p = 0; p<m + n - 1; p++){

				go(k, p);
				//printmap();
				if (check()){ answer = 1; break; }
			}
			if (answer)break;
		}

		if (answer)break;
		turn90();
	}

	return answer;
}