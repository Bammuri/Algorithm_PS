#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 1987654321
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int N, D[16][1<<16],W[16][16],P,state;
string str;


int func(int Ycnt,int state) {
	//cout << cur << " " << Ycnt << "\n";
	if (Ycnt >= P)
		return 0;

	int& ret = D[Ycnt][state];
	
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (state & (1 << i)) {
			for (int j = 0; j < N; j++) {
				if (state & (1 << j)) continue;

				ret = min(ret, func(Ycnt + 1, state|(1<<j)) + W[i][j]);
			}
		}
	}

	return ret;
}


int main() {
	cin >> N;
	FOR(i, N)
		FOR(j, N)
			cin >> W[i][j];
	cin >>str>>P;

	memset(D, -1, sizeof(D));
	
	int Ycnt = 0;

	FOR(i,N){
		if (str[i] == 'Y') {
			state |=  (1 << i);
			Ycnt++;
		}
	}
	int ans;
	if (Ycnt >= P) {
		cout << "0";
	}
	else {
		ans=func(Ycnt, state);

		if (ans == INF) {
			cout << "-1";

		}
		else {
			cout << ans;
		}
	}

	return 0;
}