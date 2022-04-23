#include <iostream>
#include <string>
using namespace std;

int N, M, R, C;
string targetMap[100];
string zeroMap[100];

int map_match()
{
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (targetMap[i][j] != zeroMap[i][j])
				return 0;
		}
	}
	*/



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (targetMap[i][j] != zeroMap[i][j])
				return 0;
		}
	}
	return 1;
}


int solve(int cnt,int si,int sj) {

	if (map_match())
		return cnt;
	else if (cnt > N* M)
		return -1;

	int flag = 0;
	int i = si;
	int j = sj;
	for (; i < N; i++) {
		for (; j < M; j++) {

			if (targetMap[i][j] != zeroMap[i][j]) {
				if (i + R - 1 < N && j + C - 1 < M) {
					for (int k = 0; k < R; k++) {//i + R - 1< N
						for (int h = 0; h < C; h++) {//j + C - 1< M
							if (zeroMap[i + k][j + h] == '1')
								zeroMap[i + k][j + h] = '0';
							else
								zeroMap[i + k][j + h] = '1';
						}
					}
					flag = 1;
					break;
				}
			}
			
		}
		j = 0;
		if (flag)
			break;
	}
	return solve(cnt + 1, i , j);
}

int main() {

	cin >> N >> M >> R >> C;

	while (N != 0 && M != 0 && R != 0 && C != 0) {

		for (int i = 0; i < N; i++) 
			cin >> targetMap[i];


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				zeroMap[i] += "0";
			
		}
		
		
		cout << solve(0,0,0) << "\n";
		for (int i = 0; i < N; i++) {
			zeroMap[i].clear();
		}
		cin >> N >> M >> R >> C;
	}
	

	return 0;
}