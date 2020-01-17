#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1987654321
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
using namespace std;

int N;
int W[16][16], D[16][1 << 16];



int func(int cur, int visited) {

	if (visited == (1<<N)-1) {
		if (W[cur][0] != 0)
			return W[cur][0];
		
		return INF;
	}

	int &ret = D[cur][visited];
	if (ret != -1) 
		return ret;
	
	ret = INF;

	for (int i = 0; i < N; i++) {
		if ( visited & (1 << i) || W[cur][i] == 0) continue;
		//cout << cur << " " << i<<"\n";
		ret = min(ret, func(i, visited | (1 << i)) + W[cur][i]);

	}

		return ret;
}

int main() {
	cin >> N;
	memset(D, -1, sizeof(D));
	FOR(i, N) {
		FOR(j, N) {
			cin >> W[i][j];
		}
	}

	cout << func(0, 1);


	return 0;
}