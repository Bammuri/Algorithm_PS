#include <iostream>
using namespace std;
int X, Y, Z, ans=0;
int mx = 1000000000;
int mn = 0;
int main() {

	cin >> X >> Y;

	Z = (double)Y*100 / X ;
	double ZZ = Z;
	if ((double)Y*100 / X  >= 99.0) {
		cout << -1;
		return 0;
	}
	//cout << Z << ZZ;

	int tx = (mn + mx) / 2;
	while (1) {
	
		ZZ = (double)(Y+tx)*100 / (X+tx) ;
		//cout << (double)Z <<" "<<(double) ZZ <<" "<<tx<< "\n";
		if ((double) ZZ -Z >= 1.0) {
			if (ans == 1) break;
			if (ans == tx) break;
			ans = tx;

			mx = tx - 1;
		}
		else {
			
			mn = tx + 1;
		}
		tx = (mn + mx+1) / 2;

	}
	
	cout << ans;
	return 0;
}