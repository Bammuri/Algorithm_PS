#include <iostream>
using namespace std;
long long  t,K,C, bong,person,idx;

long long compute[1000000][4];



int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> K >> C;

		//bong * C - K * person = 1;

		compute[0][2] = K;
		compute[0][1] = -K / K;
		compute[1][2] = C;
		compute[1][0] = C / C;
		bool f = false;
		
		if (C == 1) {
			if (K + 1 <= 1000000000)
				cout << K + 1 << "\n";
			else
				cout << "IMPOSSIBLE" << "\n";
			continue;
		}
		else if (K == 1) {
			cout << 1 << "\n";
			continue;
		}
		
		

		for(idx = 2; compute[idx - 1][2] != 1; idx++){
			if (compute[idx - 2][2] % compute[idx - 1][2] == 0) {
				cout << "IMPOSSIBLE" << "\n";
				f = 1;
				break;
			}
			
			compute[idx][2] = compute[idx - 2][2] % compute[idx - 1][2];
			//cout << "compute[idx][2]" << compute[idx][2] << "\n";
			compute[idx][3] = compute[idx - 2][2] / compute[idx - 1][2];
			//cout << "compute[idx][3]" << compute[idx][3] <<" "<< compute[idx - 2][2] <<" "<< compute[idx - 1][2] << "\n";
			compute[idx][0] = compute[idx - 2][0] - compute[idx - 1][0]* compute[idx][3];
			//cout << "compute[idx][0]" << compute[idx][0] <<" "<< compute[idx - 1][0] << "\n";
			compute[idx][1] = compute[idx - 2][1] - compute[idx - 1][1] * compute[idx][3];

			//cout << "idx"<<idx << "\n";
		}

		if (!f) {
			long long  ans = compute[idx - 1][0];
			if (ans > 0) {
				cout << ans << "\n";
			}
			else {
				while (ans < 0) {
					ans += K;
					if (ans > 0)cout << ans << "\n";
				}
			}
		}
	}

	return 0;
}