#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define my 0

using namespace std;


int T,num,N,arr[1001],ans1,ans2;
int dp[2][1001][1001];



int MakeBig(int turn,int x,int y) {

	if (x ==  y) {
		if (turn == my) {
			return arr[x];
		}
		else {
			return 0;
		}
	}


	int& ret = dp[turn][x][y];
	if (ret != -1) 
		return ret;

	if (turn == my) 
		ret = max(MakeBig(!turn, x + 1, y) + arr[x], MakeBig(!turn, x, y - 1) + arr[y]);
	
	else 
		ret = min(MakeBig(!turn, x + 1, y), MakeBig(!turn, x, y - 1));
	
	return ret;
}



int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}

		memset(dp, -1, sizeof(dp));

		cout << MakeBig( 0 , 0 , N-1)<<"\n";


	}

	return 0;
}